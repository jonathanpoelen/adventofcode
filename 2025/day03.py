#!/usr/bin/env python3
from typing import Iterable
from functools import partial

if 1:
  lines = open('input').read().splitlines()
else:
  lines = '''\
987654321111111
811111111111119
234234234234278
818181911112111
'''.splitlines()

bank_of_batteries = [[int(c) for c in line]
                     for line in lines]

def largest_possible_joltage(joltages: Iterable[int], nb_baterries: int) -> int:
  joltage = 0
  last_pos = 0
  iend = len(joltages) - nb_baterries + 1
  for iteration in range(nb_baterries):
    imax = joltages.index(max(joltages[last_pos:iend+iteration]), last_pos)
    joltage = joltage * 10 + joltages[imax]
    last_pos = imax+1
  return joltage

part1 = partial(largest_possible_joltage, nb_baterries=2)
part2 = partial(largest_possible_joltage, nb_baterries=12)

r1 = sum(map(part1, bank_of_batteries))
r2 = sum(map(part2, bank_of_batteries))
print(f'{r1 = }')  # 17229
print(f'{r2 = }')  # 170520923035051

