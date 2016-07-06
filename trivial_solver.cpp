#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  double rvalue;
  cin >> rvalue;
  int dist_count;
  cin >> dist_count;

  double* distribution = new double[dist_count];
  for (size_t i = 0; i < dist_count; i++) {
    cin >> distribution[i];
  }

  //This solution can fit in first loop, but trivial_solver should be
  //straightforward (if not dumb)
  double counter = 0;
  for (size_t i = 0; i < dist_count; i++) {
    counter += distribution[i];
    if (rvalue < counter) {
      cout << i;
      return 0;
    }
  }

  cout << "error";
  return 1;
}
