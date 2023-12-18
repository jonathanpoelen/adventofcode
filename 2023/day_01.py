#!/bin/python
import sys
import re

digit_map = {name: f'{i+1}' for i, name in enumerate((
  'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'
))}

patt1 = re.compile(fr'[0-9]|{"|".join(digit_map)}')
patt2 = re.compile(fr'[0-9]|{"|".join(name[::-1] for name in digit_map)}')

def extract_digit(l, patt, rev = False):
  d = next(patt.finditer(l))[0]
  if rev:
    d = d[::-1]
  return digit_map.get(d, d)

print(sum(
  int(extract_digit(l, patt1) + extract_digit(l[::-1], patt2, True))
  for l in sys.stdin
))
