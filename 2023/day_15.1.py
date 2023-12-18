#!/bin/python
import sys

def HASH(s):
  r = 0
  for c in s:
    r += ord(c)
    r *= 17
    r %= 256
  return r

print(sum(map(HASH, sys.stdin.read().rstrip().split(','))))
