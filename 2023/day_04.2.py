#!/bin/python
import sys
import re

sep = re.compile('[|:]')

def compute(n, wins, cards):
  wins = set(map(int, wins.split()))
  return sum(int(c) in wins for c in cards.split())

deck = [
  [1, compute(*sep.split(l))]
  for l in sys.stdin
]

for i, l in enumerate(deck):
  for ii in range(i+1, max(i+1+l[1], len(l))):
    deck[ii][0] += l[0]

print(deck)
print(sum(
  l[0]
  for l in deck
))
