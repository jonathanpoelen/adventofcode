#!/bin/python
import sys
import heapq

g = [[int(c) for c in l] for l in sys.stdin.read().splitlines()]

w = len(g[0])
h = len(g)

min_loss = w*h*9

paths = {}

def append(a, x, y, d, step, current_loss):
  global min_loss

  if 0 <= x < w and 0 <= y < h:
    current_loss += g[y][x]

    k = (x,y,d,step)
    if paths.get(k, min_loss) <= current_loss:
      return
    paths[k] = current_loss

    if x == w-1 and y == h-1 and step >= 4:
      min_loss = min(min_loss, current_loss)
      return

    heapq.heappush(a, (x, y, current_loss, d, step))

queue = [(1,0, g[0][1], (1,0), 1)]

while queue:
  x, y, current_loss, d, step = heapq.heappop(queue)
  #print(len(paths), len(queue))
  if step >= 4:
    dd = (0,1) if d[0] else (1,0)
    append(queue, x+dd[0], y+dd[1], dd, 1, current_loss)
    dd = (-dd[0], -dd[1])
    append(queue, x+dd[0], y+dd[1], dd, 1, current_loss)
  if step != 10:
    append(queue, x+d[0], y+d[1], d, step+1, current_loss)

print(min_loss)
