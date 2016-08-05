#include <iostream>

using namespace std;

// Greatest Common Divisor
// Pass positive arguments or suffer
// GCC should have optimize this tail recursion
long gcd(long a, long b) {
  if (b > a)
    return gcd(b, a);
  else
    if (b != 0)
      return gcd(b, a % b);
    else
      return a;
}

// Least Common Multiple
long lcm(long a, long b) {
  return (a * b) / gcd(a, b);
}


struct rational {
  long num;
  long den;

  // No time to explain - be friend!
  friend ostream& operator<<(ostream& output, const rational& r) {
     output << r.num << "/" << r.den;
     return output;
  }
};


//  x is real number to approx
//  maxden is the maximum denominator allowed
rational rationalize(double x, long maxden) {
  // Based on http://www.ics.uci.edu/~eppstein/numth/frap.c
  /*
  ** find rational approximation to given real number
  ** David Eppstein / UC Irvine / 8 Aug 1993
  **
  ** With corrections from Arno Formella, May 2008
  **
  ** based on the theory of continued fractions
  ** if x = a1 + 1/(a2 + 1/(a3 + 1/(a4 + ...)))
  ** then best approximation is found by truncating this series
  ** (with some adjustments in the last term).
  **
  ** Note the fraction can be recovered as the first column of the matrix
  **  ( a1 1 ) ( a2 1 ) ( a3 1 ) ...
  **  ( 1  0 ) ( 1  0 ) ( 1  0 )
  ** Instead of keeping the sequence of continued fraction terms,
  ** we just keep the last partial product of these matrices.
  */

  long m[2][2];
  double startx = x;
  long ai;

  /* initialize matrix */
  m[0][0] = m[1][1] = 1;
  m[0][1] = m[1][0] = 0;

  /* loop finding terms until denom gets too big */
  while (m[1][0] *  ( ai = (long)x ) + m[1][1] <= maxden) {
    long t;
    t = m[0][0] * ai + m[0][1];
    m[0][1] = m[0][0];
    m[0][0] = t;
    t = m[1][0] * ai + m[1][1];
    m[1][1] = m[1][0];
    m[1][0] = t;
      if (x==(double)ai) break;     // AF: division by zero
      x = 1/(x - (double) ai);
      if (x>(double)0x7FFFFFFF) break;  // AF: representation failure
  }

  rational result;
  result.num = m[0][0];
  result.den = m[1][0];
  return result;
}

/* For test purposes */
int main(int argc, char const *argv[]) {
  cout << gcd(4, 8) << endl;      // 4
  cout << gcd(45, 54) << endl;    // 9
  cout << gcd(1206, 234) << endl; // 18

  cout << lcm(4, 8) << endl;      // 8
  cout << lcm(45, 54) << endl;    // 270
  cout << lcm(1206, 234) << endl; // 15678

  cout << rationalize(3.14, 1000) << endl; // 157/50
  cout << rationalize(2.12, 1000) << endl; // 53/25
  cout << rationalize(1.875, 1000) << endl; // 15/8
  cout << rationalize(25.667, 1000) << endl; // 25667/1000
  cout << rationalize(3.1415, 1000) << endl; // 2975/947

  return 0;
}
