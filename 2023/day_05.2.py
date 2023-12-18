#!/bin/python
import sys

it = iter(sys.stdin)
seeds = list(map(int, next(it).split(':', 1)[1].split()))
seeds = [(seeds[i], seeds[i] + seeds[i+1]) for i in range(0, len(seeds), 2)]
print(f'{seeds = }')
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
  r = set()
  used = []
  for t in to_map:
    mid = (max(seed[0], t[1]), min(seed[1], t[1] + t[2]))
    if mid[0] < mid[1]:
      print(f'{t=} -> {mid=}')
      d = t[0] - t[1]
      r.add((mid[0] + d, mid[1] + d))
      used.append(mid)

    #print(t, ' => ', left, mid, right)

  rest = [seed]
  print(f'{used=}')
  for rng in used:
    rest2 = []
    for seed in rest:
      if rng[0] <= seed[0] < rng[1]:
        seed = (rng[1], seed[1])
      if rng[0] <= seed[1] < rng[1]:
        seed = (seed[0], rng[0])
      if seed[0] < seed[1]:
        if rng[1] < seed[0] or seed[1] < rng[0]:
          rest2.append(seed)
        else:
          rest2.extend(p for p in ((seed[0], rng[0]), (rng[1], seed[1])) if p[0] < p[1])
    rest = rest2
  print(f'{r=}')
  r.update(rest)
  return r

def run(seeds):
  for to_map in m:
      seeds = [seed
               for seed in seeds
               for seed in convert(seed, to_map)]
  return seeds

print(min(seed[0] for seed in seeds for seed in run([seed])))
