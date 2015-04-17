#!/bin/bash
TOOLPATH=$1
source ${TOOLPATH}/tool/common.sh

t=`get_first_fail`
make DEBUG_ARGS="< tests/$t/$t.in" debug
