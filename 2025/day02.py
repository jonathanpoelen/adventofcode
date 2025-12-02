#!/usr/bin/env python3
if 1:
  text = open('input').read()
else:
  text = '11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124'

rngs = [rng.split('-') for rng in text.split(',')]
# print(rngs)

def gen_invalid_id1(start: int, end: int, total_digits: int) -> int:
  power = 10 ** (total_digits // 2)
  midpart = start // power
  while True:
    for n in range(midpart, power):
      n = n * power + n
      if n > end:
        return
      if start <= n:
        yield n
    midpart = power
    power *= 10


def gen_invalid_id2(start: int, end: int, start_total_digits: int, end_total_digits: int) -> int:
  start_total_digits = max(start_total_digits, 2)
  for nb_digits in range(1, end_total_digits // 2 + 1):
    for total_digits in range(start_total_digits, end_total_digits+1):
      if total_digits % nb_digits:
        continue

      midpart = 10 ** (nb_digits - 1)
      mul = total_digits // nb_digits
      for n in range(midpart, midpart * 10):
        #print(f'* {start=} {n=} {mul=} {nb_digits=}/{total_digits=}  {int(str(n) * mul)}')
        n = int(str(n) * mul)
        if n > end:
          break
        if start <= n:
          #print(n, start, end)
          yield n


r1 = 0
r2 = set()

for start, end in rngs:
  n = len(start)
  r1 += sum(gen_invalid_id1(int(start), int(end), n))
  r2 |= set(gen_invalid_id2(int(start), int(end), n, len(end)))

print(f'{r1 = }') # 12599655151
print(f'r2 = {sum(r2)}') # 20942028255
