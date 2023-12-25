#!/bin/python3
import sys

s = sys.stdin.read()
g = s.splitlines()
h = len(g)
w = len(g[1])
iend = w*h - (2 + w)
print(f'{w=} {h=} {iend=}')

g = {y*w+x: (1, -1, w, -w) for y,l in enumerate(g) for x,c in enumerate(l) if c != '#'}
g.pop(1)
g.pop(w*h - 2)

#print(f'{g=}')

# removes invalid paths
for pos,dirs in g.items():
  dirs = tuple(d for d in dirs if d+pos in g)
  g[pos] = dirs
  if pos == iend:
    continue

#print(f'{g=}')

g = {pos: tuple((pos+d,1) for d in dirs) for pos,dirs in g.items()}

#print(f'{g=}')

start = next(iter(g))

removed = []
for pos,dirs in g.items():
  if len(dirs) != 2 or pos == start or pos == iend:
    continue
  removed.append(pos)
  ((pos1,step1),(pos2,step2)) = dirs
  g[pos1] = tuple(((i,step) if i != pos else (pos2,step2+step)) for i,step in g[pos1])
  g[pos2] = tuple(((i,step) if i != pos else (pos1,step1+step)) for i,step in g[pos2])

for i in removed:
  g.pop(i)

#print(f'{g=}')

#gg = ''.join(s.splitlines())
#print('\n'.join(''.join(
#  gg[i]*3 if i not in g else f'{i:<3}' for i in range(y*w,y*w+w)
#) for y in range(h)))
#print(len(g))

max_step = 0

def compute(pos, step, dejavu):
  #print(pos, step, dejavu)
  dejavu.add(pos)
  #print(' ', tuple(t for t in g[pos] if t[0] not in dejavu))
  for pos2,step2 in g[pos]:
    if pos2 not in dejavu:
      if pos2 != iend:
        compute(pos2, step+step2, dejavu)
      else:
        global max_step
        max_step = max(max_step, step+step2)
  dejavu.remove(pos)

compute(start, 2, set())

print(max_step)
