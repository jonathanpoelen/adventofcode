#!/bin/python
import sys

def compute(l):
  n = len(l)
  ifree = 0
  r = 0
  for i,c in enumerate(l):
    if c == 'O':
      r += (n - ifree)
      ifree += 1
    elif c == '#':
      ifree = i+1
  return r

print(sum(compute(list(l)) for l in zip(*sys.stdin.read().splitlines())))
