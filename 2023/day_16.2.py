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

g = sys.stdin.read().splitlines()

w = len(g[0])
h = len(g)

def process(beams, g):
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
  return sum(i > 0 for l in g for c,i in l)

print(max(
  max(
    process([(0,y,right)], [[[c, 0] for c in l] for l in g])
    for y in range(h)
  ),
  max(
    process([(w-1,y,left)], [[[c, 0] for c in l] for l in g])
    for y in range(h)
  ),
  max(
    process([(x,0,down)], [[[c, 0] for c in l] for l in g])
    for x in range(w)
  ),
  max(
    process([(x,h-1,up)], [[[c, 0] for c in l] for l in g])
    for x in range(w)
  ),
))
