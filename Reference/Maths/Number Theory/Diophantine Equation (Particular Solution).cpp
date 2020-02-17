// 11
#include "Extended Euclidean Algorithm.cpp"
typedef long long int li;

// returns the i-th solution or {0, 0} if no solutions
pair<li, li> diophantineSol(li a, li b, li c, li i) {
  li d, x, y;
  tie(d, x, y) = extendedGCD(a, b);
  if (c % d) return {0, 0};
  return {c / d * x + i / d * b,
          c / d * y - i / d * a};
}