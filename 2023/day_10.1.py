#!/bin/python
import sys

m = {c: (a, b, (-b[0], -b[1]), (-a[0], -a[1])) for c, a, b in (
  ('|', (0, 1), (0, 1)),
  ('-', (1, 0), (1, 0)),
  ('L', (0, 1), (1, 0)),
  ('J', (0, 1), (-1, 0)),
  ('7', (1, 0), (0, 1)),
  ('F', (0, -1), (1, 0)),
)}

g = sys.stdin.read()
w = g.find('\n')
g = g.replace('\n', '')
h = len(g) // w
p = g.find('S')

def advance(c, prev):
  t = m[c]
  if t[0] == prev:
    return t[1]
  if t[2] == prev:
    return t[3]

advance(g[p+1], t:=(1,0)) or advance(g[p-1], t:=(-1,0)) or advance(g[p+w], t:=(0,1)) or (t:=(0,-1))

n = 1
while True:
  p += t[0] + t[1] * w
  c = g[p]
  if c == 'S':
    break
  l = m[c]
  t = l[1] if l[0] == t else l[3]
  n += 1

print(n // 2)
