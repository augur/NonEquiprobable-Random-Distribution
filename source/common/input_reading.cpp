#include "input_reading.hpp"

void input_read(size_t& dist_count, double*& distribution,
                size_t& rvalue_count, double*& rvalues) {
  cin >> dist_count;
  distribution = new double[dist_count];
  for (size_t i = 0; i < dist_count; i++) {
    cin >> distribution[i];
  }

  cin >> rvalue_count;
  rvalues = new double[rvalue_count];
  for (size_t i = 0; i < rvalue_count; i++) {
    cin >> rvalues[i];
  }
}
