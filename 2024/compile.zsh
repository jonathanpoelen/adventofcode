#!/bin/zsh
compile() {
  local TIMEFMT='%*E'
  time timeout 8 \
    ${COMP:-g++} -I ${INC:-~/projects/jln.mpl/include} -DPART=${PART:-1} \
    -fdiagnostics-color=always -std=c++17 \
    -fsyntax-only "$@" \
}
compile "$@" |& sed -E 's/jln::mp:://g;s/number<([0-9]+)>/_\1/g'
