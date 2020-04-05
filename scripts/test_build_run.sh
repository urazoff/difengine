#!/bin/bash

ROUTE_DIR=$(pwd)

meson build
cd build
BUILD_DIR=$(pwd)
ninja
cd $ROUTE_DIR/tests/api
python3 $ROUTE_DIR/scripts/run_tests.py $BUILD_DIR
