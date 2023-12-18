#!/bin/python
import sys

def run(l):
  l = [int(x) for x in l.split()]
  firsts = []
  while any(l):
    firsts.append(l[0])
    l = [l[i] - l[i-1] for i in range(1, len(l))]
  r = 0
  firsts.reverse()
  for x in firsts:
    r = x - r
  return r

print(sum(map(run, sys.stdin)))
