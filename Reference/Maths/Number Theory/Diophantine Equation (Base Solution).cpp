// 9
#include "Extended Euclidean Algorithm.cpp"
typedef long long int li;

pair<li, li> diophantineBase(li a, li b, li c) {
  li d, x, y;
  tie(d, x, y) = extendedGCD(a, b);
  if (c % d) return {0, 0};
  return {c / d * x, c / d * y};
}