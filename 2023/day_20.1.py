#!/bin/python
import sys
import re
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
  return (t[1], (factories[t[0]](t[1]), t[2]))

mods = dict(map(parse, patt.findall(sys.stdin.read())))

def get_next_mod(name, src):
  mod = mods.get(name)
  if mod:
    mod = mod[0]
    mod.attach(src)
    return mod
  return None

broadcaster = Broadcaster()
for (mod, s) in mods.values():
  if not mod:
    mod = broadcaster
  mod.dests = [get_next_mod(name, mod) for name in s.split(', ')]
  print(mod, mod.dests)

print()

counters = [0, 0]
states = deque()
for _ in range(1000):
  states.append((False, broadcaster))
  counters[0] += 1
  while states:
    b,mod = states.popleft()
    for dest in mod.dests:
      counters[b] += 1
      if dest:
        bb = dest.pulse(b, mod)
        print(f'{mod} -> {b} -> {dest}')
        if bb is not None:
          states.append((bb, dest))
    #states.extend((dest.pulse(b, mod), mod) for dest in mod.dests)
  print()

print(counters)
print(counters[0] * counters[1])
