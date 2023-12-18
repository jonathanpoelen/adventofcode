#!/bin/python
import sys

cs = 'SF7JL-|.'

m = {cs.find(c): (a, b, (-b[0], -b[1]), (-a[0], -a[1])) for c, a, b in (
  ('|', (0, 1), (0, 1)),
  ('-', (1, 0), (1, 0)),
  ('L', (0, 1), (1, 0)),
  ('J', (0, 1), (-1, 0)),
  ('7', (1, 0), (0, 1)),
  ('F', (0, -1), (1, 0)),
)}

s = sys.stdin.read()
w = s.find('\n')
s = s.replace('\n', '')
h = len(s) // w
p = s.find('S')
g = list(map(cs.find, s))

def advance(c, prev):
  t = m[c]
  if t[0] == prev:
    return t[1]
  if t[2] == prev:
    return t[3]

advance(g[p+1], t:=(1,0)) or advance(g[p-1], t:=(-1,0)) or advance(g[p+w], t:=(0,1)) or (t:=(0,-1))

#print('\n'.join(''.join(map(str, g[i:i+w])) for i in range(0, w*h, w)))

g[p] = 0
n = 1
while True:
  p += t[0] + t[1] * w
  c = g[p]
  g[p] = 0
  if c == 0:
    break
  l = m[c]
  t = l[1] if l[0] == t else l[3]
  n += 1


m = {
  'S': ((0, 1, 0), (1, 1, 1), (0, 1, 0)),
  '.': ((0, 0, 0), (0, 0, 0), (0, 0, 0)),
  '|': ((0, 1, 0), (0, 1, 0), (0, 1, 0)),
  '-': ((0, 0, 0), (1, 1, 1), (0, 0, 0)),
  'L': ((0, 1, 0), (0, 1, 1), (0, 0, 0)),
  'J': ((0, 1, 0), (1, 1, 0), (0, 0, 0)),
  '7': ((0, 0, 0), (1, 1, 0), (0, 1, 0)),
  'F': ((0, 0, 0), (0, 1, 1), (0, 1, 0)),
}

gg = [x
  for cy in range(0, w*h, w)
  for i in (0,1,2)
  for cx in range(w)
  for x in m[s[cy+cx] if g[cy+cx] == 0 else '.'][i]
]

#print('\n'.join(''.join(map(str, gg[i:i+w*3])) for i in range(0, w*h*3*3, w*3)))

ground = cs.find('.')
coords = [0]
gg[0] = 2
ww = w*3
hh = h*3
for i in coords:
  for j in (1, -1, ww, -ww):
    j += i
    if 0 <= j < ww*hh and gg[j] == 0:
      gg[j] = 2
      coords.append(j)

#print('\n'.join(''.join(map(str, gg[i:i+ww])) for i in range(0, ww*hh, ww)))
#print('\n'.join(''.join(('.' if i==9 else ' ' if i==1 else str(i)) for i in gg[i:i+ww]) for i in range(0, ww*hh, ww)))

print(n // 2, sum(gg[cx+cy] == 0
  for cy in range(ww, ww*hh, ww*3)
  for cx in range(1, ww, 3)
))
