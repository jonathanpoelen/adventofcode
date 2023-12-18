#!/bin/python
import sys
import re

re_sep = re.compile('(\d+) (\w+)')

def line(l):
  counter = {}
  for m in re_sep.finditer(l):
    counter[m[2]] = max(counter.get(m[2], 0), int(m[1]))
  r = 1
  for x in counter.values():
    r *= x
  return r

print(sum(
  line(l.split(':', 1)[1])
  for l in sys.stdin
))
