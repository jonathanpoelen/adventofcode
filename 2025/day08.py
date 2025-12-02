#!/usr/bin/env python3
from functools import reduce
from itertools import combinations
from operator import mul
from math import dist

if 1:
  limit_part1 = 1000
  text = open('input').read()
else:
  limit_part1 = 10
  text = '''\
162,817,812
57,618,57
906,360,560
592,479,940
352,342,300
466,668,158
542,29,236
431,825,988
739,650,466
52,470,668
216,146,977
819,987,18
117,168,530
805,96,715
346,949,466
970,615,88
941,993,340
862,61,35
984,92,344
425,690,689
'''

points = [tuple(map(int, line.split(','))) for line in text.splitlines()]
nb_points = len(points)

close_indices = sorted(
  (
    (dist(points[i], points[j]), i, j)
    for i,j in combinations(range(len(points)), 2)
  ),
  key=lambda t: t[0]
)


def merge(clusters: list[set[int]], i: int, j: int) -> set[int]:
  s1 = clusters[i]
  s2 = clusters[j]
  if id(s1) != id(s2):
    s2 |= s1
    for j in s1:
      clusters[j] = s2
  return s2


clusters = [{i} for i in range(nb_points)]

for _, i, j in close_indices[:limit_part1]:
  merge(clusters, i, j)

unique_clusters = {id(s): s for s in clusters}.values()
r1 = reduce(mul, sorted(map(len, unique_clusters))[-3:])


for _, i, j in close_indices[limit_part1:]:
  s = merge(clusters, i, j)
  if len(s) == nb_points:
    r2 = points[i][0] * points[j][0]
    break


print(f'{r1 = }')  # 131580
print(f'{r2 = }')  # 6844224
