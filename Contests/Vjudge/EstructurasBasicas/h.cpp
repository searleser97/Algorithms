
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, n) for (int _ = x; _ > n; _--)
#define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fos(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;
// 12
void _main(int tc) {
  li n, x, y;
  cin >> n >> x >> y;
  vector<pairii> v(n);
  vector<li> cost(n);
  multiset<pairii> ms;
  li ans = 0, mod = 1e9 + 7;
  rep(i, n) {
    cin >> v[i].fi >> v[i].se;
    ms.insert({v[i].se, v[i].fi});
  }

  sort(v.begin(), v.end());

  rep(i, n) {
    cost[i] = x + y * (v[i].se - v[i].fi);
    if (ms.size() && ms.begin()->fi < v[i].fi) {
      auto it = ms.lower_bound({v[i].fi, 0});
      int prevRight = (--it)->fi;
      if (y * (v[i].se - prevRight) < cost[i]) {
        cost[i] = y * (v[i].se - prevRight);
        ms.erase(it);
      }
    }
  }

  rep(i, n) {
    ans = (ans + cost[i]) % mod;
  }

  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}