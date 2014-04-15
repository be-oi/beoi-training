#!/bin/bash
TOOLPATH=$1
source ${TOOLPATH}/tool/common.sh

catbef () {
	OLDIFC=$IFC
	IFC='\n' # Make read stop ignoring space at the beginning of lines
	cat $1 | while read line; do echo -e "$2$line"; done
	IFC=$OLDIFC
}
catbefcol () {
  echo -en "\033[$3m"
  catbef "$1" "$2\033[$3m"
  echo -en "\033[0m"
}
catbefr () {
  catbefcol $1 $2 31
}
catbefg () {
  catbefcol $1 $2 32
}
catbefb () {
  catbefcol $1 $2 33
}

echocol () {
  echo -en "\033[3$2m"
  echo "$1"
  echo -en "\033[0m"
}
echor () {
  echocol "$1" 1
}
echog () {
  echocol "$1" 2
}
echob () {
  echocol "$1" 3
}

in_success=false
start_success () {
  if $in_success; then
    echog "+`cat_times '-' \"$dign\"`-----------------+"
  else
    echog "`cat_times '*' \"$dign\"`*******************"
  fi
  in_success=true
}
end_success() {
  if $in_success; then
    echog "`cat_times '*' \"$dign\"`*******************"
  fi
  in_success=false
}
echo_success() {
  echog "| $1 |"
}

red_bang() {
  echo -en "\033[31m! \033[0m"
}
echo_fail() {
  red_bang
  echo "$1"
}
echo_failr() {
  red_bang
  echor "$1"
}
cat_fail_col() {
  catbefcol "$1" "`red_bang`  \033[0m" "$2"
}
cat_failr() {
  cat_fail_col "$1" 31
}
cat_failg() {
  cat_fail_col "$1" 32
}
cat_failb() {
  cat_fail_col "$1" 33
}

n_digits() {
  nd=1
  pow=10
  while [ $pow -le $1 ]; do
    let "nd++"
    let "pow *= 10"
  done
  echo $nd
}
cat_times() {
  i=0
  s=""
  while [ $i -lt $2 ]; do
    s="$s$1"
    let "i++"
  done
  echo "$s"
}

n=-1
dign=-1
first_fail=-1
if [ ! -f "tests/data" ]; then
  echo "WARNING: missing data"
else
  n=`get_n`
  dign=`n_digits $n`
fi

space_it() {
  dig1=`n_digits $1`
  echo " `cat_times ' ' $(($dign-$dig1))`$i"
}

i=1

while true; do
  if [ $n -eq -1 ] && [ ! -d "tests/$i" ]; then
    # missing data
    break
  fi
  if [ ! $n -eq -1 ] && [ $i -gt $n ]; then
    # no missing data
    break
  fi
  if [ -f "tests/$i/$i.in" ] && [ -f "tests/$i/$i.out" ]; then
    make run -s < "tests/$i/$i.in" > "tests/$i/fout"
    cd "tests/$i"
    if [ "x`cat \"$i.out\"`" != "x`cat fout`" ]; then
      end_success
      echo_failr "Test `space_it $i` failed"
      echo_fail  "Input"
      cat_failb "$i.in"
      echo_fail "Output"
      cat_failr fout
      echo_fail  "Answer"
      cat_failg "$i.out"
      rm fout
      cd ../..
      first_fail="$i"
      break
    else
      start_success
      echo_success "Test `space_it $i` succeded"
    fi
    rm fout
    cd ../..
  else
    if [ $n -eq -1 ]; then
      # missing data
      break
    fi
  fi
  let "i++"
done
if [ $first_fail -eq -1 ]; then
  start_success
  left=$((($dign-1) / 2))
  right=$(($dign-1 - $left))
  echo_success "`cat_times ' ' $left`All tests passed`cat_times ' ' $right`"
  end_success
fi
save_n "$n"
save_first_fail "$first_fail"
