#!/bin/python
import sys
from collections import Counter

ranks = {k:15-i for i,k in enumerate('AKQJT98765432')}

lines = [l.split() for l in sys.stdin]

lines = sorted(lines, key=lambda t: (
  ''.join(sorted(map(str, Counter(t[0]).values()), reverse=True)),
  (*(ranks[c] for c in t[0]),),
))

#print('\n'.join(t[0] for t in lines))
print(sum((i+1)*int(t[1]) for i,t in enumerate(lines)))
