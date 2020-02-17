// 11
#include "../Primes/Prime Factorization Pollard Rho.cpp"
// #include "../Primes/Prime Factorization.cpp"

// counts the number of integers (Xi) between 1 and n
// which are coprime (gcd(Xi, n) = 1) to n
li phi(li n) {
  Map pf = getPrimeFactors(n);
  if (pf.count(n)) return n - 1;  // if n is prime
  for (auto &p : pf) n -= n / p.first;
  return n;
}