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

void _main(int& tt) {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> Smap(26);
  rep(i, s.size()) {
    Smap[s[i] - 'a'].pb(i);
  }
  bool flag = 0;
  rep(i, t.size()) {
    if (!Smap[t[i] - 'a'].size()) {
      cout << "-1" << endl;
      return;
    }
  }

  int ans = 0, Si = 0;

  for (int ti = 0; ti < t.size();) {
    auto &v = Smap[t[ti] - 'a'];
    int res = lower_bound(v.begin(), v.end(), Si) - v.begin();
    if (res == v.size()) {
      ans++;
      res = 0;
    }
    Si = v[res] + 1;
    ti++;
  }
  cout << ans + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  rep(tt, tc) _main(tt);
}

