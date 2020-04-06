#!/bin/bash

usage="$(basename "$0") [-h] [-v] -- script to build and run Difengine tests

where:
    -h  help
    -v  verbose output"

VERBOSE=""
while getopts ':hv' option; do
  case "$option" in
    h) echo "$usage"
       exit
       ;;
    v) VERBOSE="-v"
       ;;
   \?) echo "Unknown option $OPTARG"
       echo "$usage"
       exit 1
       ;;
  esac
done

ROUTE_DIR=$(pwd)

meson build
cd build
ninja
BUILD_DIR=$ROUTE_DIR/build
SUITE_DIR=$ROUTE_DIR/tests/api
python3 $ROUTE_DIR/scripts/run_tests.py $VERBOSE $BUILD_DIR $SUITE_DIR
