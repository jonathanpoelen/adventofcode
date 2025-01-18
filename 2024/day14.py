#!/usr/bin/env python3
import re

w=101
h=103

patt = re.compile('-?\\d+')

with open('input14.txt') as f:
  robots = [
    tuple(map(int, patt.findall(line)))
    for nline, line in enumerate(f)
  ]

  for i in range(w*h):
    grid = set()
    for px,py,vx,vy in robots:
      p = (px + vx * i) % w \
        + (py + vy * i) % h * h
      if p in grid:
        break
      grid.add(p)
    else:
      print("\n".join("".join(('#' if x+yh in grid else '.')
                      for x in range(w)) for yh in range(0, h*h, h)))
      print(i)
      break
