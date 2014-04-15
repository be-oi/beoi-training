read_th() {
  left="$(($2 - 1))"
  OLDIFC=$IFC
  IFC='\n' # Make read stop ignoring space at the beginning of lines
  cat $1 |
  while read line; do
    if [ $left -eq 0 ]; then
      echo "$line"
      break
    fi
    let "left--"
  done
  IFC=$OLDIFC
}
get_n() {
  echo `read_th "tests/data" 1`
}
get_first_fail() {
  echo `read_th "tests/data" 2`
}
save() {
  echo -e "$1\n$2" > "tests/data"
}
save_n() {
  save "$1" "`get_first_fail`"
}
save_first_fail() {
  save "`get_n`" "$1"
}
