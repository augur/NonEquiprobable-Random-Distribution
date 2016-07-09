#!/bin/bash
BUILD_DIR="./build"
DIS_GEN_SRC="./distrib_generator.cpp"
DIS_GEN_BIN="$BUILD_DIR/distrib_generator"
SOLVER_SRC="./trivial_solver.cpp"
SOLVER_BIN="$BUILD_DIR/trivial_solver"
RVALUE_SRC="./random_value.cpp"
RVALUE_BIN="$BUILD_DIR/random_value"

PROBLEM_DIR="./problem"
PROBLEM_INPUT="$PROBLEM_DIR/input.txt"
PROBLEM_DISTR_SIZE=100000
PROBLEM_ROLLS=10000
PROBLEM_SEED=$1
PROBLEM_ANSWERS="$PROBLEM_DIR/answers.txt"



#Compiler select
if [ $(uname -s) == "Darwin" ]
  then
    COMPILER='clang++ -std=c++11 -stdlib=libc++ -O3 -Wall'
    echo "Compiler: Clang"
  else
    COMPILER='g++ -std=c++11 -O3 -Wall'
    echo "Compiler: GCC"
fi



rm -rf $BUILD_DIR && mkdir -p $BUILD_DIR
$COMPILER -o "$DIS_GEN_BIN" "$DIS_GEN_SRC"
$COMPILER -o "$SOLVER_BIN" "$SOLVER_SRC"
$COMPILER -o "$RVALUE_BIN" "$RVALUE_SRC"


#TODO run asserts on trivial_solver


echo "Problem 1: Single distribution, many random rolls"
rm -rf $PROBLEM_DIR && mkdir -p $PROBLEM_DIR

echo "Generating input file..."
echo "$PROBLEM_DISTR_SIZE" >> $PROBLEM_INPUT
echo "$($DIS_GEN_BIN $PROBLEM_DISTR_SIZE $PROBLEM_SEED)" >> $PROBLEM_INPUT
echo "$PROBLEM_ROLLS" >> $PROBLEM_INPUT
echo "$($RVALUE_BIN $PROBLEM_ROLLS $PROBLEM_SEED)" >> $PROBLEM_INPUT

echo "Generating answers..."
$SOLVER_BIN < $PROBLEM_INPUT > $PROBLEM_ANSWERS

echo "Measuring trivial algorithm performance..."
time $SOLVER_BIN < $PROBLEM_INPUT > /dev/null

#echo "Problem 2: Many distributions, single random roll on each"
