// 5
int Log2(int n) {
  int lg2 = 0;
  while (n) lg2++, n >>= 1;
  return lg2;
}
// 3
int Log2(int n) {
  return sizeof(n) - __builtin_clz(n);
}