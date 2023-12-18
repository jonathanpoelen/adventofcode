#!/bin/python
import sys

def run(l):
  r = 0
  l = [int(x) for x in l.split()]
  while any(l):
    r += l[-1]
    l = [l[i] - l[i-1] for i in range(1, len(l))]
  return r

print(sum(map(run, sys.stdin)))
