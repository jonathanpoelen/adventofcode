#!/usr/bin/env python3
file = 'input'

# L30 = -30
# R30 =  30
rotations = ( (-1 if line[0] == 'L' else 1) * int(line[1:])
              for line in open(file) )

r1 = 0
r2 = 0

point = 50
for n in rotations:
  point += n

  r2 += abs(point) // 100
  # non zero to zero or negative => +1
  r2 += (point <= 0 < point - n)

  point %= 100
  r1 += (not point)

print(f'{r1=}\n{r2=}')
#r1=1048
#r2=6498
