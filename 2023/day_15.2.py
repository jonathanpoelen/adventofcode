#!/bin/python
import sys

def HASH(s):
  r = 0
  for c in s:
    r += ord(c)
    r *= 17
    r %= 256
  return r

boxes = [{} for _ in range(256)]

def process(s):
  if s[-1] == '-':
    label = s[:-1]
    h = HASH(label)
    boxes[h].pop(label, None)
  else:
    label, n = s.split('=', 1)
    h = HASH(label)
    boxes[h][label] = n

for s in sys.stdin.read().rstrip().split(','):
  process(s)

print(sum((i+1) * (slot+1) * int(n) for i,box in enumerate(boxes) for slot,(label,n) in enumerate(box.items())))
