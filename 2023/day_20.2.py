#!/bin/python
import sys
import re
import math
from collections import deque

class FlipFlop:
  state = False

  def __init__(self, name):
    self.name = name

  def __repr__(self):
    return f'%{self.name} = {self.state}'

  def attach(self, src):
    pass

  def pulse(self, b, src):
    if b:
      return None
    self.state = not self.state
    return self.state


class Conjunction:
  def __init__(self, name):
    self.name = name
    self.states = {}

  def __repr__(self):
    l = " | ".join(f'{mod.name}={v}' for mod,v in self.states.items())
    return f'&{self.name} | {l}'

  def attach(self, src):
    self.states[src] = False

  def pulse(self, b, src):
    self.states[src] = b
    return not all(self.states.values())


class Broadcaster:
  pass


patt = re.compile(r'([%&]?)(\w+) -> ([^\n]+)')
factories = {
  '&': Conjunction,
  '%': FlipFlop,
  '': lambda _: None,
}

def parse(t):
  return (t[1], (factories[t[0]](t[1]), t[2].split(', ')))

mods = dict(map(parse, patt.findall(sys.stdin.read())))
rx_referencer = next(mod for name,(mod,l) in mods.items() if 'rx' in l)

def get_next_mod(name, src):
  mod = mods.get(name)
  if mod:
    mod = mod[0]
    mod.attach(src)
    return mod
  return None

broadcaster = Broadcaster()
for mod,l in mods.values():
  if not mod:
    mod = broadcaster
  mod.dests = [get_next_mod(name, mod) for name in l]
  #print(mod, mod.dests)

highs = {mod: 0 for mod in rx_referencer.states}

#print()

def process():
  i = 0
  states = deque()
  while True:
    i += 1
    states.append((False, broadcaster))
    while states:
      b,mod = states.popleft()
      for dest in filter(None, mod.dests):
        bb = dest.pulse(b, mod)
        #print(f'{mod} -> {b} -> {dest}')
        if bb is not None:
          if dest == rx_referencer:
            if all(highs.values()):
              return math.lcm(*highs.values())
            if b and not highs[mod]:
              highs[mod] = i
          states.append((bb, dest))
    #print()

print(process())
