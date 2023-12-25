#!/bin/python3
import sys

g = sys.stdin.read().splitlines()
h = len(g)
w = len(g[1])
iend = w*h - (2 + w)
#print(w,h,iend)

m = {
  '>': (1,),
  '<': (-1,),
  'v': (w,),
  '^': (-w,),
  '.': (1, -1, w, -w),
}

g = {y*w+x: dirs for y,l in enumerate(g) for x,c in enumerate(l) if (dirs := m.get(c))}
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

g = {pos: tuple(pos+d for d in dirs) for pos,dirs in g.items()}

#print(f'{g=}')

start = next(iter(g))
queue = [(start, set())]
step = 0
while queue:
  pos, dejavu = queue.pop()
  if pos == iend:
    step = max(step, len(dejavu) + 2)
    continue
  dejavu.add(pos)
  dirs = tuple(pos for pos in g[pos] if pos not in dejavu)
  if dirs:
    for i in range(len(dirs)-1):
      queue.append((dirs[i], set(dejavu)))
    queue.append((dirs[-1], dejavu))

print(step)
