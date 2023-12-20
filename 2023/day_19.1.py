#!/bin/python
import sys
import re
import operator

workflows, ratings = sys.stdin.read().split('\n\n', 1)

patt_num = re.compile(r'\d+')
patt_rule = re.compile(r'(?:([xmas])([<>])(\d+):)?(\w+)')

m = {
  '<': operator.lt,
  '>': operator.gt,
  'x': 0,
  'm': 1,
  'a': 2,
  's': 3,
}

def parse_worflow(name, _, rules):
  return (name, [(
    (m[rating], m[op], int(n), ref) if rating else (0, operator.gt, -1, ref)
  ) for (rating, op, n, ref) in patt_rule.findall(rules)])

workflows = dict(parse_worflow(*l.partition('{')) for l in workflows.splitlines())
ratings = [[int(n) for n in patt_num.findall(l)] for l in ratings.splitlines()]

def process(rangings):
  workflow = workflows['in']
  #print()
  while True:
    for (rating, op, n, ref) in workflow:
      #print(part, op, n, ref, op(rangings[part], n))
      if op(rangings[rating], n):
        if (workflow := workflows.get(ref)):
          break
        elif ref == 'A':
          return sum(rangings)
        else:  # ref == 'R'
          return 0

print(sum(map(process, ratings)))
