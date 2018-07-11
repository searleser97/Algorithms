int lcm(int a, int b) {
  int c = gcd(a, b);
  return c ? a / c * b : 0;
}