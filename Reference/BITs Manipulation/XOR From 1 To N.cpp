// 8
int xorToN(int n) {
  switch (n & 3) {
    case 0: return n;
    case 1: return 1;
    case 2: return n + 1;
    case 3: return 0;
  }
}