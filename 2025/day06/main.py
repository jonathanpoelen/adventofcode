#!/usr/bin/env python3
from operator import add, mul
from functools import reduce
from itertools import starmap
from typing import Callable, Iterable

if 1:
  text = open('input').read()
else:
  text = '''\
123 328  51 64 
 45 64  387 23 
  6 98  215 314
*   +   *   +  
'''

lines = text.splitlines()

ops = [add if c == '+' else mul
       for c in lines.pop()
       if c != ' '
      ]


def part1(lines: Iterable[str], ops: Iterable[Callable[int, [int,int]]]) -> int:
  numbers = ([int(n) for n in line.split()]
             for line in lines
            )
  return sum(starmap(reduce, zip(ops, zip(*numbers))))


def part2(lines: Iterable[str], ops: Iterable[Callable[int, [int,int]]]) -> int:
  result = 0
  numbers = []
  op_it = iter(ops)
  for cols in zip(*lines):
    s = ''.join(cols)
    try:
      numbers.append(int(s))
    except ValueError:
      op = next(op_it)
      result += reduce(op, numbers)
      numbers = []

  if numbers:
    op = next(op_it)
    result += reduce(op, numbers)

  return result


r1 = part1(lines, ops)
r2 = part2(lines, ops)

print(f'{r1 = }')  # 6417439773370
print(f'{r2 = }')  # 11044319475191
