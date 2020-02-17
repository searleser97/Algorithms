#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, n) for (int _ = x; ~_; _--)
#define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fos(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;

typedef unordered_map<li, int> Map;

Map getPrimeFactors(li n) {
  Map pf;
  while (~n & 1) pf[2]++, n >>= 1;
  for (li i = 3; i * i <= n; i += 2)
    while (!(n % i)) pf[i]++, n /= i;
  if (n > 1) pf[n]++;
  return pf;
}

li phi(li n) {
  Map pf = getPrimeFactors(n);
  if (pf.count(n)) return n - 1;
  for (auto &p : pf) n -= n / p.first;
  return n;
}

void _main(int tc) {
  li a, m;
  cin >> a >> m;
  cout << phi(m / __gcd(a, m)) << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}