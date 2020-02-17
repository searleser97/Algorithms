// 10
#include "Modulo with negative numbers.cpp"
typedef long long int li;

// gcd(a, b) = ax + by
tuple<li, li, li> extendedGCD(li a, li b) {
  if (!a) return {b, 0, 1};
  li d, x, y;
  tie(d, x, y) = extendedGCD(mod(b, a), a);
  return {d, y - floor((double) b / a) * x, x};
}  // {gcd(a, b), x, y}