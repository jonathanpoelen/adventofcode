#!/bin/python
import sys

it = iter(sys.stdin)
seeds = list(map(int, next(it).split(':', 1)[1].split()))
next(it)
m = [[]]
a = m[0]
for l in it:
  if len(l) < 2:
    a = []
    m.append(a)
  elif '0' <= l[0] <= '9':
    a.append((*map(int, l.split()),))

def convert(seed, to_map):
  r = [seed + t[0] - t[1]
       for t in to_map
       if t[1] <= seed and seed < t[1] + t[2]]
  return r if r else [seed]

def run(seeds):
  for to_map in m:
      print(to_map, seeds, end=' ')
      seeds = [seed
               for seed in seeds
               for seed in convert(seed, to_map)]
      print('->', seeds)
  return seeds

print(min(seed for seed in seeds for seed in run([seed])))
