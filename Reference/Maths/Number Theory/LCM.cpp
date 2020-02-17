// 6
#include "GCD.cpp"

int lcm(li a, li b) {
  int d = gcd(a, b);
  return d ? a / d * b : 0;
}