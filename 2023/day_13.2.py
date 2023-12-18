#!/bin/python
import sys

def is_smudged_mirrored(puzzle, i, n):
  correction = True
  for j in range(n):
    for a,b in zip(puzzle[i+j], puzzle[i-j-1]):
      if a != b:
        if not correction:
          return False
        correction = False
  return not correction

def compute(puzzle):
  n = len(puzzle)
  for i in range(1, n):
    if is_smudged_mirrored(puzzle, i, min(i, n-i)):
      return i
  return 0

print(sum(
  compute(puzzle := a.splitlines()) * 100 or compute(list(zip(*puzzle)))
  for a in sys.stdin.read().split('\n\n')
))
