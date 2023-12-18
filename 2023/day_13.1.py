#!/bin/python
import sys

def compute(puzzle):
  n = len(puzzle)
  r = 0
  for i in range(1, n):
    d = min(i, n-i)
    if all(puzzle[i+j] == puzzle[i-j-1] for j in range(d)):
      #print(i, puzzle[i])
      # r = max(r, i)
      return i
  return r

print(sum(
  compute(puzzle := a.splitlines()) * 100 or compute(list(zip(*puzzle)))
  for a in sys.stdin.read().split('\n\n')
))
