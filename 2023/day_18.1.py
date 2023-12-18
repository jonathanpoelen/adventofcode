#!/bin/python
import sys

to_tuple = lambda d,n,_: (0 if d == 'R' else 1 if d == 'L' else 2 if d == 'D' else 3, int(n))
cmds = [to_tuple(*l.split(' ')) for l in sys.stdin]

lw,lh = 0,0
rw,rh = 0,0
sizes = [0,0,0,0]
for d,n in cmds:
  sizes[d] += n
  lw = min(lw, sizes[0] - sizes[1])
  lh = min(lh, sizes[2] - sizes[3])
  rw = max(rw, sizes[0] - sizes[1])
  rh = max(rh, sizes[2] - sizes[3])
w = abs(lw) + rw + 3
h = abs(lh) + rh + 3

#print(w, h)

g = [0] * (w*h)

incs = [1, -1, w, -w]
pos = w+1 + abs(lw) + abs(lh) * w
for d,n in cmds:
  step = incs[d]
  for i in range(pos + step, pos + n*step + step, step):
    g[i] = 1
  pos += n*step

#print('\n'.join(''.join(('.','#')[g[i]] for i in range(i,i+w)) for i in range(0, w*h, w)))

coords = [0]
g[0] = 2
occupied = 1
for i in coords:
  for j in (1, -1, w, -w):
    j += i
    if 0 <= j < w*h and g[j] == 0:
      g[j] = 2
      occupied += 1
      coords.append(j)

#print('\n'.join(''.join(('.','#','x')[g[i]] for i in range(i,i+w)) for i in range(0, w*h, w)))

print(len(g) - occupied)
