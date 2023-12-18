#!/bin/python
import sys

def compute(s, j, ns, ins, e='', d=0):
  if ins == len(ns):
    r = 1 if all('#' != c for c in s[j:]) else 0
    print(r)
    return r

  r = 0
  n = ns[ins]
  ie = len(s) - n + 1
  for i in range(j, ie):
    if all('.' != c for c in s[i:i+n]):
      if i+n >= len(s) or s[i+n] != '#':
        print(f' {e}{s[j:i]}{"#"*n} {s[i+n:]}', j, i, d)
        r += compute(s, i+n+1, ns, ins+1, f'{e}{s[j:i]}{"#"*n}!', d+1)
    if s[i] == '#':
      break
  return r

n = 0
for l in sys.stdin:
  s, ns = l.split(' ', 1)
  ns = [int(n) for n in ns.split(',')]
  r = compute(s, 0, ns, 0)
  n += r
  print(s, ns, r)
print(n)
