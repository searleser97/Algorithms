// 12
#include "./Modular Multiplication.cpp"

// O(lg(p))
lli pow(lli a, lli p, lli m) {
  a %= m;
  lli ans = 1;
  while (p) {
    if (p & 1LL) ans = multiply(ans, a, m);
    a = multiply(a, a, m), p >>= 1;
  }
  return ans;
}