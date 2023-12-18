#!/bin/python
import sys
import re

patt = re.compile(r'(\w+) = \((\w+), (\w+)\)')

cmd = [(0 if c == 'L' else 1) for c in sys.stdin.readline().strip()]
n = len(cmd)

network = {k: (l,r) for (k,l,r) in patt.findall(sys.stdin.read())}

k = 'AAA'
i = 0
while k != 'ZZZ':
  k = network[k][cmd[i % n]]
  i += 1

print(i)
