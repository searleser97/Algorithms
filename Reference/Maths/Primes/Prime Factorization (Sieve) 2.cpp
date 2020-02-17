// 18
#include "Primes Sieve.cpp"

typedef long long int li;
// if li == __int128_t: use map<li, int> Map;
typedef unordered_map<li, int> Map;

// O(sqrt(N)) n <= sieve.size() ^ 2
Map getPrimeFactors(li n) {
  Map pf;
  for (int& p : primes) {
    if (p * p > n) break;
    int c;
    while (n % p == 0) n /= p, c++;
    if (c) pf[p] = c;
  }
  if (n > 1) pf[n] = 1;
  return pf;
}