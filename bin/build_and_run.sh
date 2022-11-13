#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
PROJECT_DIR=$SCRIPT_DIR/../
BUILD_DIR=$PROJECT_DIR/build/$(hostname)/

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake $PROJECT_DIR
make -j8

$BUILD_DIR/main
