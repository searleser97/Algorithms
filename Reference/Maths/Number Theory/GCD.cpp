// 4
// recursive
int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}
// 8
// iterative
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}