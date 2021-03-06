#!/bin/bash

if [ "$#" -lt 2 ]; then
    echo "Usage: ./launcher.sh <distribution size> <number of random rolls> [optional: random seed]"
    exit
fi


PROBLEM_DISTR_SIZE=$1
PROBLEM_ROLLS=$2
PROBLEM_SEED=$3
PROBLEM_DIR="./problem"
PROBLEM_INPUT="$PROBLEM_DIR/input.txt"
PROBLEM_ANSWERS="$PROBLEM_DIR/answers.txt"

PROBLEM_ATTEMPT_PATH="./source/attempts"
PROBLEM_ATTEMPT_PATTERN="attempt_"

BUILD_DIR="./build"

COMMON_SRC_PATH="./source/common"

UTILS_PATH="./source/utilities"
DIS_GEN_SRC="$UTILS_PATH/distrib_generator.cpp"
RVALUE_SRC="$UTILS_PATH/random_value.cpp"
VALDTR_SRC="$UTILS_PATH/validator.cpp"

DIS_GEN_BIN="$BUILD_DIR/distrib_generator"
RVALUE_BIN="$BUILD_DIR/random_value"
VALDTR_BIN="$BUILD_DIR/validator"
TSOLVER_BIN="$BUILD_DIR/${PROBLEM_ATTEMPT_PATTERN}trivial"
MSOLVER_BIN="$BUILD_DIR/${PROBLEM_ATTEMPT_PATTERN}mock"

#TIME_UTIL='/usr/bin/time -f time:\t\t%e\nmem(kB):\t%M'

#Compiler select
if [ $(uname -s) == "Darwin" ]
  then
    COMPILER='clang++ -std=c++11 -stdlib=libc++ -O3 -Wall -I'$COMMON_SRC_PATH
    echo "Compiler: clang++"
  else
    COMPILER='g++ -std=c++11 -O3 -Wall -I'$COMMON_SRC_PATH
    echo "Compiler: g++"
fi



echo "Compiling utilities..."
rm -rf $BUILD_DIR && mkdir -p $BUILD_DIR
$COMPILER -o "$DIS_GEN_BIN" "$DIS_GEN_SRC"
$COMPILER -o "$RVALUE_BIN" "$RVALUE_SRC"
$COMPILER -o "$VALDTR_BIN" "$VALDTR_SRC"


for i in $( ls $PROBLEM_ATTEMPT_PATH/* ); do
  bin_name=$( basename $i)
  bin_name="$PROBLEM_ATTEMPT_PATTERN${bin_name%%.*}"
  echo "Compiling solution $bin_name ..."
  $COMPILER -o "$BUILD_DIR/$bin_name" "$i" $COMMON_SRC_PATH/*
done

#TODO run asserts on trivial_solver

echo "Problem 1: Single distribution, many random rolls"
rm -rf $PROBLEM_DIR && mkdir -p $PROBLEM_DIR

echo "Generating input file..."
echo "$PROBLEM_DISTR_SIZE" >> $PROBLEM_INPUT
echo "$($DIS_GEN_BIN $PROBLEM_DISTR_SIZE $PROBLEM_SEED)" >> $PROBLEM_INPUT
echo "$PROBLEM_ROLLS" >> $PROBLEM_INPUT
echo "$($RVALUE_BIN $PROBLEM_ROLLS $PROBLEM_SEED)" >> $PROBLEM_INPUT

echo "Generating answers with trivial solution..."
$TSOLVER_BIN < $PROBLEM_INPUT > $PROBLEM_ANSWERS

HORIZONTAL_RULE="====================================="

echo $HORIZONTAL_RULE
echo "Measuring mock (no actual solving) solution ..."
time $MSOLVER_BIN < $PROBLEM_INPUT > /dev/null
echo $HORIZONTAL_RULE

echo "Measuring trivial solution ..."
time $TSOLVER_BIN < $PROBLEM_INPUT > /dev/null
echo $HORIZONTAL_RULE

for i in $( ls $BUILD_DIR/$PROBLEM_ATTEMPT_PATTERN[[:digit:]]* ); do
  echo "Measuring $( basename $i) ..."
  time $i < $PROBLEM_INPUT > /dev/null
  echo "Validating answers..."
  $i < $PROBLEM_INPUT | $VALDTR_BIN $PROBLEM_ROLLS "$PROBLEM_ANSWERS"
  echo $HORIZONTAL_RULE
  #$VALDTR_BIN $PROBLEM_ROLLS "$PROBLEM_ANSWERS"  < "$i < $PROBLEM_INPUT"
  #if [[ $(diff <( cat $PROBLEM_ANSWERS ) <( $i < $PROBLEM_INPUT )) ]]; then
  #  echo "Validation failed! (For Attempt 1 this is okay, see README)"
  #else
  #  echo "Validation OK!"
  #fi
done

#echo "Problem 2: Many distributions, single random roll on each"
