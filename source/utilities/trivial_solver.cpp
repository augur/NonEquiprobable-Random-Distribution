#include <iostream>
#include "input_reading.cpp" //just too lazy to include .h

using namespace std;

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

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
