#include <iostream>
#include <algorithm>

#include "input_reading.cpp" //just too lazy to include .h

using namespace std;

int binary_range_search(double*& array, size_t lo, size_t hi, double val) {
  if (lo == hi)
    return lo;
  size_t mid = floor((lo + hi) / 2);
  if (val < array[mid]) {
    return binary_range_search(array, lo, mid, val);
  } else {
    return binary_range_search(array, mid + 1, hi, val);
  }
}


int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  double* enhanced_dist = new double[dist_count];

  double sum = 0;
  for (size_t i = 0; i < dist_count; i++) {
    enhanced_dist[i] = distribution[i] + sum;
    sum += distribution[i];
    //cout << enhanced_dist[i] << endl;
  }

  for (size_t i = 0; i < rvalue_count; i++) {
    int index = binary_range_search(enhanced_dist, 0, dist_count - 1, rvalues[i]);
    if (index < 0) {
      cout << "error ";
    } else {
      cout << index << " ";
    }
  }
}
