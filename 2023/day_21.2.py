#!/bin/python
import sys
from functools import reduce

s = sys.stdin.read()
g = [c in ('.', 'S') for c in s]
w = s.index('\n') + 1
g += (False,) * w
s += '#' * w  # for show_grid

def show_grid():
  print(''.join(
    ''.join(('O' if pos in positions else s[pos]) for pos in range(y, y+w))
    for y in range(0, len(g), len(g) // w)
  ))
  print()

def process(positions, _):
  return set(pos+step for pos in positions for step in steps if g[pos+step])

steps = (1, -1, w, -w)
positions = reduce(process, range(64), ((s.index('S'),)))

print(len(positions))
