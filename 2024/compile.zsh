#!/bin/zsh
compile() {
  if (( ${MEM:-0} )); then
    tt() { /usr/bin/time --format='%Es - %MK' $@ }
  else
    tt() {
      local TIMEFMT='%*E'
      time $@
    }
  fi
  tt timeout ${TIMEOUT:-8} \
    ${COMP:-g++} -I ${INC:-~/projects/jln.mpl/include} -DPART=${PART:-1} \
    -DJLN_MP_MAX_CALL_ELEMENT=${MAX_ELEM:-30000} \
    -fdiagnostics-color=always -std=c++20 \
    -fsyntax-only "$@"
}

if [[ ${COMP:-} = *clang* ]]; then
  compile "$@" -fbracket-depth=20000
else
  compile "$@"
fi |& sed -E 's/jln::mp:://g;s/number<([0-9]+)>/_\1/g'
