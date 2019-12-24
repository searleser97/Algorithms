// 10
// pf = prime factors

#include "../Number Theory/GCD.cpp"
#include "./Is Prime Miller Rabin.cpp"

typedef long long int li;
// if li == __int128_t: use map<li, int> Map;
typedef unordered_map<li, int> Map;

li _abs(li a) { return a < 0 ? -a : a; }
// 10
li getRandomDivisor(li n) {
  if (~n & 1) return 2;
  li c = 1 + rand() % (n - 1), a = 2, b = 2, d = 1;
  auto f = [&](li x) {
    return (multiply(x, x, n) + c) % n;
  };
  while (d == 1)
    a = f(a), b = f(f(b)), d = gcd(_abs(a - b), n);
  return d;
}
// 10
void getpf(li n, Map &pf) {
  if (n == 1LL) return;
  if (isPrime(n)) {
    pf[n]++;
    return;
  }
  li divisor = getRandomDivisor(n);
  getpf(divisor, pf);
  getpf(n / divisor, pf);
}
// 6
// ~O(N^(1/4))
Map getPrimeFactors(li n) {
  Map pf;
  getpf(n, pf);
  return pf;
}