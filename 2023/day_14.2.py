#!/bin/python
import sys
from functools import cache

@cache
def compute(t):
  l = list(t)
  #print(l, '-> ', end='')
  n = len(l)
  ifree = 0
  for i,c in enumerate(l):
    if c == 'O':
      l[i] = '.'
      l[ifree] = c
      ifree += 1
    elif c == '#':
      ifree = i+1
  #print(l)
  return l

def cycle(g):
  g = [compute(t) for t in zip(*g)]
  #print()
  g = [compute(t) for t in zip(*g)]
  #print()
  g = [compute(tuple(reversed(t))) for t in zip(*g)]
  #print()
  g = [compute(tuple(reversed(t))) for t in zip(*g)]
  #print()
  g = [list(reversed(t)) for t in reversed(g)]
  s = '\n'.join(''.join(l) for l in g)
  #print(s)
  #print()
  #print()
  return [g, s]

g = sys.stdin.read()
gnext = [g.splitlines(), g, None, 0]
m = {}
i = 0
#e = 100000
e = 1000000000
while i < e:
  #print(i)
  if not (gg := gnext[2]) and not (gg := m.get(gnext[1])):
    gg = [*cycle(gnext[0]), None, len(m)]
    m[gnext[1]] = gg

  gnext[2] = gg
  gnext = gnext[2]
  if (gg := m.get(gg[1])):
    d = len(m) - gg[3]
    i += (e - i) // d * d

  i += 1

g = gnext[0]
#print(g)
print(sum((len(t)-i if c == 'O' else 0) for t in zip(*g) for i,c in enumerate(t)))
