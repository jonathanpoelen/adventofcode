#!/bin/python
import sys
from functools import cache

@cache
def compute(s, ns):
  if len(ns) == 0:
    return 1 if all('#' != c for c in s) else 0

  r = 0
  n = ns[0]
  ie = len(s) - n + 1
  for i in range(ie):
    if all('.' != c for c in s[i:i+n]):
      if i+n >= len(s) or s[i+n] != '#':
        r += compute(s[i+n+1:], ns[1:])
    if s[i] == '#':
      break
  return r

n = 0
coef = 5
for l in sys.stdin:
  s, ns = l.split(' ', 1)
  s = '?'.join([s] * coef).strip('.')
  ns = tuple([int(n) for n in ns.split(',')] * coef)
  r = compute(s, ns)
  n += r
  #print(s, ns, r)
print(n)
