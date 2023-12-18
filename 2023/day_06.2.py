#!/bin/python
import sys

times, dists = [list(map(int, l.split(':',1)[1].replace(' ', '').split())) for l in sys.stdin]

r = 1
for i in range(len(times)):
  m = dists[i]
  t = times[i]
  r *= sum(n * (t-n) > m for n in range(t))
print(r)
