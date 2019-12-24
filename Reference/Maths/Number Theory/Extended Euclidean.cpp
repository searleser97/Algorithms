// 23
// r = remainder

typedef __int128_t lli;
// gcd(a, b) = ax + by
vector<lli> extendedGCD(lli a, lli b) {
  if (a > 0 && b == 0) return {a, 1, 0};
  lli x = 1, y, prevx, prevy = 1, q, r;
  while (true) {
    q = a / b, r = a - b * q;
    if (!r) break;
    a = b, b = r;
    x -= prevx * q;
    swap(x, prevx);
    y -= prevy * q;
    swap(y, prevy);
  }
  // gcd = b, x = prevx, y = prevy
  return {b, prevx, prevy};
}