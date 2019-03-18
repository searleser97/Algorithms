// 5
int clz(int n) {
  return __builtin_clz(n);
  // return __builtin_clzl(n); for long
  // return __builtin_clzll(n); for long long
}
// 6
int clz(int n) {
  // return sizeof(n) * 8 - bitCount(n);
  int c = 0;
  while (n) c++, n >>= 1;
  return sizeof(n) * 8 - c;
}