// 13
// divs = divisors

typedef long long int li;
typedef vector<li> V;

// O(sqrt(N))
V getDivisors(li n) {
  V divs;
  for (li i = 1; i * i <= n; i++)
    if (!(n % i)) {
      divs.push_back(i);
      if (i * i != n) divs.push_back(n / i);
    }
  return divs;
}