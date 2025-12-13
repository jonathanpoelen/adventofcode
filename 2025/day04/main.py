#!/usr/bin/env python3

if 1:
  text = open('input').read()
else:
  text = '''\
..@@.@@@@.
@@@.@.@.@@
@@@@@.@.@@
@.@@@@..@.
@@.@@@@.@@
.@@@@@@@.@
.@.@.@.@@@
@.@@@.@@@@
.@@@@@@@@.
@.@.@@@.@.
'''

grid = text.splitlines()
w = len(grid[0])
h = len(grid)

adjacents = (
  (-1, -1),
  (-1,  0),
  (-1,  1),
  ( 0, -1),
  ( 0,  1),
  ( 1, -1),
  ( 1,  0),
  ( 1,  1),
)

type XY = tuple[int, int]

def remove_rolls(rolls: set[XY]) -> tuple[set[XY], int]:
  next_rolls = set(
    (x,y)
    for x,y in rolls
    if sum((x+dx, y+dy) in rolls for dx,dy in adjacents) >= 4
  )
  return next_rolls, len(rolls) - len(next_rolls)


rolls = set(
  (x,y)
  for x in range(w)
  for y in range(h)
  if grid[y][x] == '@'
)

(rolls, nb_removed) = remove_rolls(rolls)

r1 = nb_removed
r2 = r1
while nb_removed:
  (rolls, nb_removed) = remove_rolls(rolls)
  r2 += nb_removed
  #print(nb_removed)

print(f'{r1 = }')  # 1505
print(f'{r2 = }')  # 9182
