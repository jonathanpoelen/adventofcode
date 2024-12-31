#!/bin/zsh
compile() {
  local TIMEFMT='%*E'
  time timeout 8 \
    ${COMP:-g++} -I ${INC:-~/projects/jln.mpl/include} -DPART=${PART:-1} \
    -DJLN_MP_MAX_CALL_ELEMENT=30000 \
    -fdiagnostics-color=always -std=c++20 \
    -fsyntax-only "$@" \
}

if [[ ${COMP:-} = *clang* ]]; then
  compile "$@" -fbracket-depth=2000
else
  compile "$@"
fi |& sed -E 's/jln::mp:://g;s/number<([0-9]+)>/_\1/g'
