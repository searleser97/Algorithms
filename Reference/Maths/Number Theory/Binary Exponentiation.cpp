// 10
typedef __int128_t lli;

lli binPow(lli a, lli p) {
  lli ans = 1LL;
  while (p) {
    if (p & 1LL) ans *= a;
    a *= a, p >>= 1LL;
  }
  return ans;
}