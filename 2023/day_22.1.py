#!/bin/python3
import sys

border_len = 10

def parse(l):
  xyz1, xyz2 = l.split('~', 1)
  xyz1, xyz2 = xyz1.split(','), xyz2.split(',')

  x1,y1,z1 = int(xyz1[0]), int(xyz1[1])*border_len, int(xyz1[2])
  x2,y2,z2 = int(xyz2[0])+1, (int(xyz2[1])+1)*border_len, int(xyz2[2])+1

  if y2 - y1 != border_len:
    rng = range(y1 + x1, y2 + x1, border_len)
  else:
    rng = range(y1 + x1, y1 + x2)

  mask = sum(1 << i for i in rng)

  return z1,rng,z2-z1,mask

def fall(d):
  xy_max = [0] * border_len**2
  gtop = {}
  gbottom = {}

  for i,(_,rng,nz,m) in enumerate(d):
    z = max(xy_max[ii] for ii in rng)
    z2 = z + nz

    for ii in rng:
      xy_max[ii] = z2

    t = (i, m)
    gtop.setdefault(z2, []).append(t)
    gbottom.setdefault(z, []).append(t)

  return gtop, gbottom

d = sorted(map(parse, sys.stdin), key=lambda t: t[0])
gtop, gbottom = fall(d)

#for name,g in (('gbottom', gbottom), ('gtop', gtop),):
#  print(name)
#  print('\n'.join(f'{z=:<4} | {i=:<5} {m:0>100b}' for z,l in sorted(g.items()) for i,m in l))
#  print()

r = set(i
  for z,l in gtop.items()
  for i,m1 in l
  if all(not (m1 & m2) for _,m2 in gbottom.get(z, ()))
)

unremovables = set()

for z,l in gbottom.items():
  for _,m1 in l:
    below = [i for i,m2 in gtop.get(z, ()) if m1 & m2]
    if len(below) > 1:
      r.update(below)
    else:
      unremovables.update(below)

r -= unremovables
print(len(r))
