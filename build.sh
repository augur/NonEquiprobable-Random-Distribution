#!/bin/bash
BUILD_DIR=./build
DIS_GEN_SRC=./distrib_generator.cpp
DIS_GEN_BIN="$BUILD_DIR/distrib_generator"


#Compiler choose
if [ $(uname -s) == "Darwin" ]
  then
    COMPILER='clang++ -std=c++11 -stdlib=libc++ -O3'
    echo "Compiler: Clang"
  else
    COMPILER='g++ -std=c++11 -O3'
    echo "Compiler: GCC"
fi



rm -rf $BUILD_DIR && mkdir -p $BUILD_DIR
$COMPILER -o "$DIS_GEN_BIN" "$DIS_GEN_SRC"
