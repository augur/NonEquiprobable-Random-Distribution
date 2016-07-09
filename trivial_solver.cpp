#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  size_t dist_count;
  cin >> dist_count;

  double* distribution = new double[dist_count];
  for (size_t i = 0; i < dist_count; i++) {
    cin >> distribution[i];
  }

  size_t rvalue_count;
  cin >> rvalue_count;

  double* rvalues = new double[rvalue_count];
  for (size_t i = 0; i < rvalue_count; i++) {
    cin >> rvalues[i];
  }

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
