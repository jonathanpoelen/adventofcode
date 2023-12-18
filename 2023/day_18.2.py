#!/bin/python
import sys

to_tuple = lambda code: (code & 0xf, code >> 4)
cmds = [to_tuple(int(l.split(' ')[2][2:-2], 16)) for l in sys.stdin]

pos = 0
lava = 1
steps = ((1,0), (0,1), (-1,0), (0,-1))
for d,n in cmds:
  x,y = steps[d]
  pos += x * n
  lava += y * n * pos + n/2

print(int(lava))
