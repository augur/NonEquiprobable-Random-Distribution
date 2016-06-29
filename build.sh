#!/bin/bash
BUILD_DIR=./build
IN_GEN_SRC=./input_generator.cpp
IN_GEN_BIN="$BUILD_DIR/input_generator"





rm -rf $BUILD_DIR && mkdir -p $BUILD_DIR
g++ -std=c++11 -O3 -o "$IN_GEN_BIN" "$IN_GEN_SRC"
