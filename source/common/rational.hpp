#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdint>

using namespace std;

long gcd(long a, long b);
long lcm(long a, long b);

struct rational {
  uint64_t num;
  uint64_t den;

  // No time to explain - be friend!
  friend ostream& operator<<(ostream& output, const rational& r) {
     output << r.num << "/" << r.den;
     return output;
  }
};

rational rationalize(double x, uint64_t maxden);

#endif
