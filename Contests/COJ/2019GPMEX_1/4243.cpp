#include <bits/stdc++.h>
using namespace std;

typedef long long int llli;
typedef long long int lli;
typedef unordered_map<lli, int> Map;
typedef vector<lli> V;

llli multiply(llli a, llli b, llli m) {
  a %= m;
  llli ans = 0;
  while (b) {
    if (b & 1)
      ans += a, ans = (ans >= m ? ans - m : ans);
    b >>= 1, a <<= 1;
    a = (a >= m ? a - m : a);
  }
  return ans;
}

lli pow(llli a, llli p, llli m) {
  a %= m;
  llli ans = 1;
  while (p) {
    if (p & 1) ans = multiply(ans, a, m);
    a = multiply(a, a, m), p >>= 1;
  }
  return ans;
}

bool isPrime(lli p, int k = 20) {
  if (p == 2 || p == 3) return 1;
  if ((~p & 1) || p == 1) return 0;
  lli d = p - 1, phi = d, r = 0;
  while (~d & 1) d >>= 1, r++;
  while (k--) {
    // set seed with: int main() { srand(time(0)); }
    lli a = 2LL + rand() % (p - 3);  // [2, p - 2]
    lli e = pow(a, d, p), r2 = r;
    if (e == 1 || e == phi) continue;
    bool flag = 1;
    while (--r2) {
      e = multiply(e, e, p);
      if (e == 1) return 0;
      if (e == phi) {
        flag = 0;
        break;
      }
    }
    if (flag) return 0;
  }
  return 1;
}

lli gcd(lli a, lli b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

lli _abs(lli a) { return a < 0 ? -a : a; }

lli randomDivisor(lli n) {
  if (~n & 1) return 2;
  lli c = 1 + rand() % (n - 1), a = 2, b = 2, d = 1;
  auto f = [&](lli x) {
    return (multiply(x, x, n) + c) % n;
  };
  while (d == 1)
    a = f(a), b = f(f(b)), d = gcd(_abs(a - b), n);
  return d;
}

void primeFactors(lli n, Map &factors) {
  if (n == 1LL) return;
  if (isPrime(n)) {
    factors[n]++;
    return;
  }
  lli divisor = randomDivisor(n);
  primeFactors(divisor, factors);
  primeFactors(n / divisor, factors);
}
// 5
Map primeFactors(lli n) {
  Map factors;
  primeFactors(n, factors);
  return factors;
}

void divisors(Map &pf, V &d, lli ans, lli p) {
  auto next = ++pf.find(p);
  for (lli k = 0; k <= pf[p]; k++, ans *= p) {
    if (next == pf.end())
      d.push_back(ans);
    else
      divisors(pf, d, ans, next->first);
  }
}

V getDivisors(lli n) {
  Map pf = primeFactors(n);
  V d;
  divisors(pf, d, 1, pf.begin()->first);
  return d;
}

int main() {
  srand(1);
  int t;
  scanf("%d", &t);
  for (int j = 1; j <= t; j++) {
    lli x;
    scanf("%lld", &x);
    lli count = 0;
    V divisors = getDivisors(2LL * x);
    for (auto &div : divisors) {
      double d =
          ((double)x / div) + ((1.00 - div) / 2.00);
      if (d > 0 && div > 1 && d == floor(d) &&
          div < x &&
          (2 * d * div + (div - 1) * div == 2 * x)) {
        count++;
      }
    }
    printf("case %d: %lld\n", j, count);
  }
}