#!/bin/python
import sys
import re

re_sep = re.compile('(\d+) (\w+)')

m = {
  'red': 12,
  'green': 13,
  'blue': 14,
}

def line(n, l):
  return int(n[5:]) if all(int(r[1]) <= m[r[2]] for r in re_sep.finditer(l)) else 0

print(sum(
  line(*l.split(':', 1))
  for l in sys.stdin
))
