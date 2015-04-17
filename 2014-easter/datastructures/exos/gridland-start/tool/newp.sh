#! /bin/bash

if [ $# -lt 1 ]; then
  echo "Missing problem name"
  exit 1
fi
cp -r ../tool/template $1
