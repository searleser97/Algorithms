// 5
typedef __int128_t lli;

lli gcd(lli a, lli b) {
  return !b ? a : gcd(b, a % b);
}
// 5
// Iterative version
lli gcdI(lli a, lli b) {
  while (b) a %= b, swap(a, b);
  return a;
}