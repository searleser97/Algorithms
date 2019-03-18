// 3
int bitCount(int n) {
  return sizeof(n) * 8 - __builtin_clz(n) + 1;
}