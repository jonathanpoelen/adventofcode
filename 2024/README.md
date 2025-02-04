Solution using C++ meta-programming.

Inputs are transformed into types and the result is computed at compile time and displayed via a compiler error.

Uses the jln.mp library (https://github.com/jonathanpoelen/jln.mp).

```sh
./compile.zsh day1.cpp
# or
PART=1 COMP=g++ INC=jln-include-path TIMEOUT=8 MEM=0 ./compile.zsh day1.cpp [compiler option...]
```

- ⚠ day 6: 2 min and 10 GiB (g++)
- ⚠ day 9: 1 min and 12 GiB (g++)
- ⚠ day 12: 35 s and 4 GiB (g++)
- ⚠ day 15: 2 min 30 s and 1.2 GiB (g++)
