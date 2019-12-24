// 14
// pf = primeFactors, divs = divisors

#include "../Primes/Prime Factorization Pollard Rho.cpp"

typedef vector<li> V;

void divisors(Map &pf, V &divs, li ans, li p) {
  auto next = ++pf.find(p);
  int power = pf[p];
  for (li k = 0; k <= power; k++, ans *= p) {
    if (next == pf.end()) divs.push_back(ans);
    else divisors(pf, divs, ans, next->first);
  }
}
// 7
// O(number of pf)
V getDivisors(li n) {
  Map pf = getPrimeFactors(n);
  V divs;
  divisors(pf, divs, 1, pf.begin()->first);
  return divs;
}