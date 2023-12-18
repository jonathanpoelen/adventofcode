#!/bin/python
import sys
import re

sep = re.compile('[|:]')

def compute(n, wins, cards):
  wins = set(map(int, wins.split()))
  n = sum(int(c) in wins for c in cards.split())
  return 2**n // 2

print(sum(
  compute(*sep.split(l))
  for l in sys.stdin
))
