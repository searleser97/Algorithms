// 7
int clz(int n) {
  return __builtin_clz(n);
  // return __builtin_clzl(n); for long
  // return __builtin_clzll(n); for long long
}