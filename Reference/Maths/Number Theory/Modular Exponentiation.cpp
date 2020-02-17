// 12
#include "./Modular Multiplication.cpp"

// O(lg(p))
li pow(li a, li p, li m) {
  a %= m;
  li ans = 1;
  while (p) {
    if (p & 1LL) ans = multiply(ans, a, m);
    a = multiply(a, a, m), p >>= 1;
  }
  return ans;
}