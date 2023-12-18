#!/bin/python
import sys

right = 0b1000
left  = 0b0100
up    = 0b0010
down  = 0b0001

dcoord = {
  right: (1, 0),
  left: (-1, 0),
  up: (0, -1),
  down: (0, 1),
}

m = {
  '.': {
    right: (right,),
    left: (left,),
    up: (up,),
    down: (down,),
  },
  '/': {
    right: (up,),
    left: (down,),
    up: (right,),
    down: (left,),
  },
  '\\': {
    right: (down,),
    left: (up,),
    up: (left,),
    down: (right,),
  },
  '-': {
    right: (right,),
    left: (left,),
    up: (right,left),
    down: (right,left),
  },
  '|': {
    right: (up,down),
    left: (up,down),
    up: (up,),
    down: (down,),
  },
}

g = [[[c, 0] for c in l] for l in sys.stdin.read().splitlines()]

w = len(g[0])
h = len(g)

beams = [(0,0,right)]
for x, y, dbeam in beams:
  if 0 <= x < w and 0 <= y < h:
    c,d = g[y][x]
    if dbeam & d:
      continue
    g[y][x][1] |= dbeam
    for dc in m[c][dbeam]:
      xx, yy = dcoord[dc]
      # print(c, (x,y), '->', (x + xx, y + yy))
      beams.append((x + xx, y + yy, dc))

# print('\n'.join(str(l) for l in g))
print(sum(i > 0 for l in g for c,i in l))
