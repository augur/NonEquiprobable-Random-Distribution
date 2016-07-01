#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
  if ((argc<2)||(argc>3)) {
    cout << "usage: distrib_generator <number of probabilities> [optional: seed]" << endl;
    return 1;
  } else {
    int num = stoi(argv[1]);
    double* probs = new double[num];
    double sum = 0;

    unsigned seed;
    if (argc == 3) {
      seed = stoi(argv[2]);
    } else {
      seed = chrono::system_clock::now().time_since_epoch().count();
    }
    default_random_engine generator (seed);
    uniform_real_distribution<double> distrib (0.0,1.0);

    for (int i = 0; i < num; i++) {
      double prob = distrib(generator);
      probs[i] = prob;
      sum += prob;
    }

    for (int i = 0; i < num; i++) {
      cout << (probs[i] / sum) << " ";
    }

    return 0;
  }
}
