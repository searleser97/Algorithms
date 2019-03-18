// 5
int popCount(int n) {
  return __builtin_popcount(n);
  // return __builtin_popcountl(n); for long
  // return __builtin_popcountll(n); for long long
}
// 5
int popCount(int n) {
  int c = 0;
  while (n) c += n & 1, n >>= 1;
  return c;
}