#include "attempt.hpp"
#include "input_reading.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  do_attempt(dist_count, distribution, rvalue_count, rvalues);

  return 0;
}
