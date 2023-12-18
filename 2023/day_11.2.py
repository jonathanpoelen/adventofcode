#!/bin/python
import sys

g = sys.stdin.read().splitlines()

coef = 1000000
dy = [coef if all('.' == c for c in l) else 1 for l in g]
dx = [coef if all('.' == c for c in l) else 1 for l in zip(*g)]

i = 0; dx = [(i:=i+x) for x in dx]
i = 0; dy = [(i:=i+x) for x in dy]

w = len(g[0])
h = len(g)

g = [(dx[x], dy[y]) for y in range(h) for x in range(w) if g[y][x] == '#']
n = len(g)

print(sum(abs(g[j][0]-g[i][0]) + abs(g[j][1]-g[i][1])
  for i in range(n)
  for j in range(i+1, n)
))
