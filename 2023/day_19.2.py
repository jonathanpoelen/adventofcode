#!/bin/python
import sys
import re
import operator
from functools import reduce

workflows, ratings = sys.stdin.read().split('\n\n', 1)

patt_rule = re.compile(r'(?:([xmas])([<>])(\d+):)?(\w+)')

m = {
  'x': 0,
  'm': 1,
  'a': 2,
  's': 3,
}

def parse_worflow(name, _, rules):
  return (name, [(
    (m[rating], op == '<', int(n) + (op != '<'), ref) if rating else (0, True, 5000, ref)
  ) for (rating, op, n, ref) in patt_rule.findall(rules)])

workflows = dict(parse_worflow(*l.partition('{')) for l in workflows.splitlines())

def compute_op(a, b, lt, limit):
  if b < limit:
    accepted = (a,b)
    rejected = None
  elif limit <= a:
    accepted = None
    rejected = (a,b)
  else:
    accepted = (a, limit-1) if a < limit-1 else None
    rejected = (limit, b)
  return (accepted, rejected) if lt else (rejected, accepted)

result = 0
steps = [(workflows['in'], [(1, 4000), (1, 4000), (1, 4000), (1, 4000)])]

while steps:
  workflow, rangings = steps.pop()
  for rating, lt, limit, ref in workflow:
    accepted, rejected = compute_op(*rangings[rating], lt, limit)
    if accepted:
      cp_rangings = rangings[:]
      cp_rangings[rating] = accepted
      if (workflow := workflows.get(ref)):
        steps.append((workflow, cp_rangings))
      elif ref == 'A':
        result += reduce(operator.mul, (b-a+1 for a,b in cp_rangings), 1)
    if rejected:
      rangings[rating] = rejected

print(result)
