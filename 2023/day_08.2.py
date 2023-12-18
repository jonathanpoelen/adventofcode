#!/bin/python
import sys
import re
import math

patt = re.compile(r'(\w+) = \((\w+), (\w+)\)')

cmd = [(0 if c == 'L' else 1) for c in sys.stdin.readline().strip()]
n = len(cmd)

network = {k: (l,r) for (k,l,r) in patt.findall(sys.stdin.read())}

r = []
for k in network.keys():
  if not k.endswith('A'):
    continue
  i = 0
  while not k.endswith('Z'):
    k = network[k][cmd[i % n]]
    i += 1
  r.append(i)

print(math.lcm(*r))
print(i)
