#!/bin/python
import sys
import re

patt = re.compile(r'\d+')
sym = re.compile(r'[^0-9.\n]')

lines = [f'.{l}.' for l in sys.stdin]
n = len(lines)
empty = '.' * len(lines[0])
lines.insert(0, empty)
lines.append(empty)

def extract(i):
  line = lines[i]
  r = 0
  for m in patt.finditer(line):
    i1, i2 = m.span()
    s = f'{line[i1-1]}{line[i2]}{lines[i-1][i1-1:i2+1]}{lines[i+1][i1-1:i2+1]}'
    r += int(m[0]) if sym.search(s) else 0
  return r

print(sum(
  map(extract, range(1,n+1))
))
