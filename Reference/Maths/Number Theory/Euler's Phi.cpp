// 11
#include "../Primes/Prime Factorization Pollard Rho.cpp"
// #include "../Primes/Prime Factorization.cpp"

// counts the number of integers (Xi) between 1 and n
// which are coprime (gcd(Xi, n) = 1) to n
lli phi(lli n) {
  if (isPrime(n)) return n - 1;
  Map pf = getPrimeFactors(n);
  for (auto &p : pf) n -= n / p.first;
  return n;
}