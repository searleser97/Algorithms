// 3
int bitCount(int n) {
  return sizeof(n) * 8 - __builtin_clz(n);
}
// 5
int bitCount(int n) {
  int c = 0;
  while (n) c++, n >>= 1;
  return c;
}