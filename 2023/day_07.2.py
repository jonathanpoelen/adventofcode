#!/bin/python
import sys
from collections import Counter

ranks = {k:15-i for i,k in enumerate('AKQT98765432J')}

lines = [l.split() for l in sys.stdin]

def tr(counter):
  if j := counter.get('J'):
    del counter['J']
    if not counter:
      return {'A': 5}
    higher = max((t[1], t[0]) for t in counter.items())
    counter[higher[1]] += j
  return counter

lines = sorted(lines, key=lambda t: (
  ''.join(sorted(map(str, tr(Counter(t[0])).values()), reverse=True)),
  (*(ranks[c] for c in t[0]),),
))

#print('\n'.join(t[0] for t in lines))
print(sum((i+1)*int(t[1]) for i,t in enumerate(lines)))
