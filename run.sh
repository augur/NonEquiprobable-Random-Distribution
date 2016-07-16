#!/bin/bash
BUILD_DIR="./build"
DIS_GEN_SRC="./distrib_generator.cpp"
DIS_GEN_BIN="$BUILD_DIR/distrib_generator"
SOLVER_SRC="./trivial_solver.cpp"
SOLVER_BIN="$BUILD_DIR/trivial_solver"
RVALUE_SRC="./random_value.cpp"
RVALUE_BIN="$BUILD_DIR/random_value"
VALDTR_SRC="./validator.cpp"
VALDTR_BIN="$BUILD_DIR/validator"

PROBLEM_DIR="./problem"
PROBLEM_INPUT="$PROBLEM_DIR/input.txt"
PROBLEM_DISTR_SIZE=1000
PROBLEM_ROLLS=1000000
PROBLEM_SEED=$1
PROBLEM_ANSWERS="$PROBLEM_DIR/answers.txt"

PROBLEM_ATTEMPT_PATTERN="attempt_*"



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
$COMPILER -o "$VALDTR_BIN" "$VALDTR_SRC"

for i in $( ls $PROBLEM_ATTEMPT_PATTERN ); do
  bin_name=$( basename $i)
  bin_name="${bin_name%%.*}"
  $COMPILER -o "$BUILD_DIR/$bin_name" "$i"
done

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

for i in $( ls $BUILD_DIR/$PROBLEM_ATTEMPT_PATTERN ); do
  echo "Measuring $i ..."
  time $i < $PROBLEM_INPUT > /dev/null
  echo "Validating answers..."
  $i < $PROBLEM_INPUT | $VALDTR_BIN $PROBLEM_ROLLS "$PROBLEM_ANSWERS" 
  #$VALDTR_BIN $PROBLEM_ROLLS "$PROBLEM_ANSWERS"  < "$i < $PROBLEM_INPUT"
  #if [[ $(diff <( cat $PROBLEM_ANSWERS ) <( $i < $PROBLEM_INPUT )) ]]; then
  #  echo "Validation failed! (For Attempt 1 this is okay, see README)"
  #else
  #  echo "Validation OK!"
  #fi
done

#echo "Problem 2: Many distributions, single random roll on each"
