// 6
#include "GCD.cpp"

int lcm(lli a, lli b) {
  int c = gcd(a, b);
  return c ? a / c * b : 0;
}