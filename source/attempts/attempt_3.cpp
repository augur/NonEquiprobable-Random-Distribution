#include <iostream>
#include <cstdint>
#include <cmath>

#include "input_reading.hpp"
#include "rational.hpp"

using namespace std;

//Commented out!
//const uint64_t memory_limit = 1000000;

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  //Implying we have no more than 65536 outcomes
  //Let memory limit be square of outcomes count
  //Uses twice (because of further uint16_t) so many bytes of memory
  uint64_t memory_limit = dist_count * dist_count;

  //Needs " + dist_count" extra size because of possible upper rounding
  uint16_t* indices = new uint16_t[memory_limit + dist_count];

  unsigned long* int_distribution = new unsigned long[dist_count];
  unsigned long total = 0;
  for (size_t i = 0; i < dist_count; i++) {
    int_distribution[i] = lround(distribution[i] * memory_limit);
    for (size_t j = total; j < total + int_distribution[i]; j++) {
      indices[j] = i;
      //std::cout << indices[j] << " ";
    }
    total += int_distribution[i];
  }
  //std::cout << std::endl << total << std::endl;

  for (size_t i = 0; i < rvalue_count; i++) {
    long int_rval = lround(rvalues[i] * (total-1));
    std::cout << indices[int_rval] << " ";
  }


}
