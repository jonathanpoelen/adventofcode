#!/usr/bin/env python3
from typing import Iterable
from bisect import bisect_right

if 1:
  text = open('input').read()
else:
  text = '''\
3-5
10-14
16-20
12-18

1
5
8
11
17
32
'''

type IdRng = tuple[int, int]


def start_rng(rng: IdRng) -> int:
  return rng[0]


def merge_overlapping_neighbor_rngs(rngs: Iterable[IdRng]) -> list[IdRng]:
  last_rng = rngs[0]
  new_rngs = []
  for rng in rngs:
    # overlapping
    if rng[0] <= last_rng[1]:
      last_rng = (last_rng[0], max(rng[1], last_rng[1]))
    else:
      new_rngs.append(last_rng)
      last_rng = rng

  new_rngs.append(last_rng)
  return new_rngs


def has_id(rngs: Iterable[IdRng], i: int) -> bool:
  idx = bisect_right(rngs, i, key=start_rng)
  if idx:
    rng = rngs[idx-1]
    return rng[0] <= i <= rng[1]
  return False


(fresh_rngs, ingredient_ids) = text.split('\n\n')

fresh_rngs = [tuple(map(int, rng.split('-'))) for rng in fresh_rngs.splitlines()]
ingredient_ids = [int(i) for i in ingredient_ids.splitlines()]

# merge overlapping ranges
fresh_rngs.sort(key=start_rng)
fresh_rngs = merge_overlapping_neighbor_rngs(fresh_rngs)


r1 = sum(has_id(fresh_rngs, i) for i in ingredient_ids)
r2 = sum(rng[1] - rng[0] + 1 for rng in fresh_rngs)

print(f'{r1 = }')  # 638
print(f'{r2 = }')  # 352946349407338
