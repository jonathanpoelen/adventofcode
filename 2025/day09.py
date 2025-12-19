#!/usr/bin/env python3
from itertools import combinations, pairwise, chain, starmap
from dataclasses import dataclass
from typing import Self
from bisect import bisect_left

if 1:
  text = open('input').read()
else:
  text = '''\
7,1
11,1
11,7
9,7
9,5
2,5
2,3
7,3
'''

points = [tuple(map(int, line.split(','))) for line in text.splitlines()]

r1 = max(
  (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1)
  for (x1,y1),(x2,y2) in combinations(points, 2)
)


type Point = tuple[int, int]


@dataclass
class IRange:
  lo: int
  hi: int

  def overlap(self, other: Self) -> bool:
    return max(self.lo, other.lo) <= min(self.hi, other.hi)

  def size(self) -> int:
    return self.hi - self.lo + 1

  def inner(self) -> 'IRange':
    return IRange(self.lo + 1, self.hi - 1)

  def __repr__(self) -> str:
    return f'[{self.lo}..={self.hi}]'


@dataclass
class Rect:
  x: IRange
  y: IRange

  @staticmethod
  def from_points(p1: Point, p2: Point) -> 'Rect':
    x1, y1 = p1
    x2, y2 = p2
    return Rect(
      IRange(min(x1,x2), max(x1,x2)),
      IRange(min(y1,y2), max(y1,y2)),
    )

  def overlap(self, other: Self) -> bool:
    return self.x.overlap(other.x) and self.y.overlap(other.y)

  def area(self) -> int:
    return self.x.size() * self.y.size()

  def inner(self) -> 'Rect':
    return Rect(self.x.inner(), self.y.inner())


lines = list(starmap(Rect.from_points, pairwise(chain(points, (points[0],)))))


def part2_v1(lines) -> int:
  return max(
    map(
      Rect.area,
      filter(
        lambda rect: not any(map(rect.inner().overlap, lines)),
        starmap(Rect.from_points, combinations(points, 2))
      )
    )
  )


def rect_x_hi(r: Rect) -> int:
  return r.x.hi

lines.sort(key=rect_x_hi)


def not_overlapping(r: Rect) -> bool:
  r = r.inner()
  hi = r.x.hi

  start = bisect_left(lines, r.x.lo, key=rect_x_hi)

  for i in range(start, len(lines)):
    r2 = lines[i]
    if hi < r2.x.lo:
      continue
    if r2.overlap(r):
      return False

  return True


r2 = max(
  map(
    Rect.area,
    filter(
      not_overlapping,
      starmap(Rect.from_points, combinations(points, 2))
    )
  )
)


print(f'{r1 = }')  # 4759531084
print(f'{r2 = }')  # 1539238860
