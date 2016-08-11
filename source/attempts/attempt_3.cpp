#include <iostream>
#include <cstdint>

#include "input_reading.hpp"
#include "rational.hpp"

using namespace std;

const uint64_t memory_limit = 100000; //Uses twice so many bytes of memory

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  rational* rationals = new rational[dist_count];
  uint64_t global_lcm = 1;
  for (size_t i = 0; i < dist_count; i++) {
    rationals[i] = rationalize(distribution[i], memory_limit);
    global_lcm = lcm(global_lcm, rationals[i].den);
    std::cout << rationals[i] << std::endl;
  }
  std::cout << global_lcm << std::endl;

  for (size_t i = 0; i < dist_count; i++) {
    //holy cow, C++ doesn't have built-in implementation of Rationals >_<
  }


}
