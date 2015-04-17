#!/bin/bash
source ../../tool/common.sh

if [ ! -d "tests" ]; then
  mkdir tests
fi
if [ ! -f "tests/data" ]; then
  save 0 -1
fi
n=`get_n`
let "n++"
if [[ -d "tests/$n" && -f "tests/$n/$n.in" && -f "tests/$n/$n.out" ]]; then
  echo "corrupted \"tests/data\""
  exit 1
fi
mkdir "tests/$n"
if [ "x$EDITOR" == "x" ]; then
  EDITOR=nano
fi
${EDITOR} "tests/$n/$n.in"
${EDITOR} "tests/$n/$n.out"
save_n "$n"
