#include <iostream>
#include <algorithm>

#include "input_reading.cpp" //just too lazy to include .h

using namespace std;

struct sorted_dist_elem {
  double value;
  size_t index;

  bool operator<(const sorted_dist_elem& other) const {
    return other.value < this->value; //! injected sorting in reversed order !
  }
};

int main(int argc, char const *argv[]) {

  size_t dist_count;
  double* distribution;
  size_t rvalue_count;
  double* rvalues;

  input_read(dist_count, distribution, rvalue_count, rvalues);

  sorted_dist_elem* sorted_dist = new sorted_dist_elem[dist_count];
  for (size_t i = 0; i < dist_count; i++) {
    sorted_dist[i].value = distribution[i];
    sorted_dist[i].index = i;
  }

  sort(sorted_dist, sorted_dist + dist_count);

  //cout << sorted_dist[0].value << " " << sorted_dist[0].index << endl;
  //cout << sorted_dist[1].value << " " << sorted_dist[1].index << endl;
  //cout << sorted_dist[2].value << " " << sorted_dist[2].index << endl;
  //return 0;

  for (size_t j = 0; j < rvalue_count; j++) {
    bool match = false;
    double counter = 0;
    for (size_t i = 0; i < dist_count; i++) {
      counter += sorted_dist[i].value;
      if (rvalues[j] < counter) {
        cout << sorted_dist[i].index << " ";
        match = true;
        break;
      }
    }
    if (!match) {
      cout << "error ";
    }
  }
}
