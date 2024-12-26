Solution using C++ meta-programming.

Inputs are transformed into types and the result is computed at compile time and displayed via a compiler error.

Uses the jln.mp library (https://github.com/jonathanpoelen/jln.mp).

```sh
./compile.zsh day1.cpp
# or
PART=2 COMP=clang++ INC=jln-include-path ./compile.zsh day1.cpp
```
