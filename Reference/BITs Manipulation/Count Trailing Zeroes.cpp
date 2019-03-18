// 5
int ctz(int n) {
  return __builtin_ctz(n);
  // return __builtin_ctzl(n); for long
  // return __builtin_ctzll(n); for long long
}
// 6
int ctz(int n) {
  int c = 0;
  n = ~n;
  while(n & 1) c++, n >>= 1;
  return c;
}