#!/bin/python
import sys

g = sys.stdin.read().splitlines()

for _ in range(2):
  i = 0
  while i < len(g):
    if all('.' == c for c in g[i]):
      g.insert(i, g[i])
      i += 1
    i += 1
  g = list(zip(*g))

w = len(g[0])
h = len(g)
#print(w,h)
g = [(x,y) for y in range(h) for x in range(w) if g[y][x] == '#']
n = len(g)

#print(g)
#print(''.join(f'{g[i]} - {g[j]} = {abs(g[j][0]-g[i][0]) + abs(g[j][1]-g[i][1])}\n'
#  for i in range(n)
#  for j in range(i+1, n)
#))
print(sum(abs(g[j][0]-g[i][0]) + abs(g[j][1]-g[i][1])
  for i in range(n)
  for j in range(i+1, n)
))
