#!/bin/bash
source ../../tool/common.sh

t=`get_first_fail`
make DEBUG_ARGS="< tests/$t/$t.in" debug
