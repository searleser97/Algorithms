// 5
int ctz(int n) {
  return __builtin_ctz(n);
  // return __builtin_ctzl(n); for long
  // return __builtin_ctzll(n); for long long
}