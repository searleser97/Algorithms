// 5
typedef long long int li;

li gcd(li a, li b) {
  return !b ? a : gcd(b, a % b);
}
// 5
// Iterative version
li gcdI(li a, li b) {
  while (b) a %= b, swap(a, b);
  return a;
}