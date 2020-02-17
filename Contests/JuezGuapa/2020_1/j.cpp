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

void _main(int tc) {
  string s;
  cin >> s;
  li ans = s.size() + 1;
  vector<int> c(26), v(26);
  rep(i, s.size()) {
    c[s[i] - 'a']++;
    rep(j, 26) {
      if (j != s[i] - 'a') {
        v[j]++;
      }
    }
  }
  
  rep(i, 26) {
    if (c[i] <= 0) continue;
    ans = (ans + (c[i] * v[i]) % 11092019) % 11092019;
  }
  cout << (ans % 11092019) << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}