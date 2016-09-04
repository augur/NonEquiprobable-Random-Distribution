#include <iostream>
#include "attempt.hpp"

using namespace std;

void do_attempt(size_t& dist_count, double*& distribution,
                size_t& rvalue_count, double*& rvalues) {

  for (size_t j = 0; j < rvalue_count; j++) {
    bool match = false;
    double counter = 0;
    for (size_t i = 0; i < dist_count; i++) {
      counter += distribution[i];
      if (rvalues[j] < counter) {
        cout << i << " ";
        match = true;
        break;
      }
    }
    if (!match) {
      cout << "error ";
    }
  }

}
