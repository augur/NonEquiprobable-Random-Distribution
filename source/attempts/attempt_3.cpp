#include <iostream>
#include <ratio>

#include "input_reading.cpp" //just too lazy to include .h

using namespace std;

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  double min_value = distribution[0];
  for (size_t i = 1; i < dist_count; i++) {
    if (distribution[i] < min_value) {
      min_value = distribution[i];
    }
  }
  double fp_mult = 1 / min_value;

  int int_mult = 1;
  for (size_t i = 0; i < dist_count; i++) {
    //holy cow, C++ doesn't have built-in implementation of Rationals >_<
  }


}
