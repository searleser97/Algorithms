// 3
int unsetIthBit(int n, int i) {
  return n & (~(1 << i));
}