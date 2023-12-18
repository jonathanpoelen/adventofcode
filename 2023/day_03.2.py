#!/bin/python
import sys
import re

patt = re.compile(r'\d+')

lines = [f'.{l}.' for l in sys.stdin]
n = len(lines)
empty = '.' * len(lines[0])
lines.insert(0, empty)
lines.append(empty)

gears = {}

def extract(i):
  line = lines[i]
  for m in patt.finditer(line):
    i1, i2 = m.span()
    if line[i1-1] == '*':
      pos = (i, i1-1)
    elif line[i2] == '*':
      pos = (i, i2)
    elif -1 != (offset := lines[i-1][i1-1:i2+1].find('*')):
      pos = (i-1, i1-1+offset)
    elif -1 != (offset := lines[i+1][i1-1:i2+1].find('*')):
      pos = (i+1, i1-1+offset)
    else:
      continue
    gears.setdefault(pos, [0]).append(int(m[0]))

for i in range(1,n+1):
  extract(i)

print(sum(
  l[-1] * l[-2] for l in gears.values()
))
