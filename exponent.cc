#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

//  x ^ 2n = (x^2) ^ n
//  x ^ (2n+1) = x * x^(2n)
//             = x * (x^2) ^ n

double exp(double base, unsigned int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    return exp( base * base, e >> 1);
  } else {
    return base * exp( base * base, e >> 1);
  }
}

bool eq(double a, double b) {
  double eps = 0.0001;
  return (a+eps > b && b+eps > a);
}

int main(int argc, char** argv) {
  assert(eq(exp(0.1,0), 1.0));
  assert(eq(exp(0.9,0), 1.0));
  assert(eq(exp(1.1,0), 1.0));

  assert(eq(exp(0.1,1), 0.1));
  assert(eq(exp(0.9,1), 0.9));
  assert(eq(exp(1.1,1), 1.1));

  assert(eq(exp(3,2), 9.0));
  assert(eq(exp(5,2), 25.0));
  assert(eq(exp(10,2), 100.0));

  assert(eq(exp(3,3), 27.0));
  assert(eq(exp(5,3), 125.0));
  assert(eq(exp(10,3), 1000.0));
}
