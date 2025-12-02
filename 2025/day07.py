#!/usr/bin/env python3
from typing import Iterable

if 1:
  text = open('input').read()
else:
  text = '''\
.......S.......
...............
.......^.......
...............
......^.^......
...............
.....^.^.^.....
...............
....^.^...^....
...............
...^.^...^.^...
...............
..^...^.....^..
...............
.^.^.^.^.^...^.
...............
'''

lines = text.splitlines()

marker = 1 << lines[0].index('S')
splitters_lines = [
  sum(
    1 << pos
    for pos, c in enumerate(lines[i])
    if c == '^'
  )
  for i in range(2, len(lines), 2)
]


def part1(splitters_lines: Iterable[int], markers: int) -> int:
  result = 0
  for splitters in splitters_lines:
    splitted = markers & splitters
    markers |= (splitted << 1) | (splitted >> 1)
    markers &= ~splitted

    result += splitted.bit_count()

  return result


def part2(splitters_lines: Iterable[int], marker: int) -> int:
  result = 1
  timelines = {marker: 1}

  for splitters in splitters_lines:
    next_timelines = {}

    for marker, nb_branchs in timelines.items():
      splitted = marker & splitters

      def add_timeline(marker):
        next_timelines[marker] = next_timelines.get(marker, 0) + nb_branchs

      if splitted:
        for new_marker in (splitted << 1, splitted >> 1):
          add_timeline(new_marker)
        result += nb_branchs
      else:
        add_timeline(marker)

    timelines = next_timelines

  return result


r1 = part1(splitters_lines, marker)
r2 = part2(splitters_lines, marker)

print(f'{r1 = }')  # 1535
print(f'{r2 = }')  # 4404709551015
