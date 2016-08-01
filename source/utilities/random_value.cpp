#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {

  size_t count = stoi(argv[1]);

  unsigned seed;
  if (argc == 3) {
    seed = stoi(argv[2]);
  } else {
    seed = chrono::system_clock::now().time_since_epoch().count();
  }
  default_random_engine generator (seed);
  uniform_real_distribution<double> distrib (0.0,1.0);

  cout.precision(15);
  for (size_t i = 0; i < count; i++) {
    cout << distrib(generator) << " ";
  }

  return 0;
}
