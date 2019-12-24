// 3
int Log2(int n) {
  return sizeof(n) * 8 - __builtin_clz(n) - 1;
}
// 5
int Log2(int n) {
  int lg2 = 0;
  while (n >>= 1) lg2++;
  return lg2;
}