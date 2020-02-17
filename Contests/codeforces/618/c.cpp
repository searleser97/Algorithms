#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, l) for (int _ = x; _ > l; _--)
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

void _main(int tc) {
  int n;
  cin >> n;
  vector<unsigned> orig(n), inv(n), pref(n), suff(n);
  
  rep(i, n) {
    cin >> orig[i];
    inv[i] = ~orig[i];
    if (i) pref[i] = pref[i - 1] & inv[i];
    else pref[i] = inv[i];
  }

  forr(i, n - 1, -1) {
    if (i == n - 1) suff[i] = inv[i];
    else {
      suff[i] = suff[i + 1] & inv[i];
    }
  }

  unsigned maxim = 0, val = 0;
  rep(i, n) {
    unsigned eval = orig[i];
    if (i) eval &= pref[i - 1];
    if (i < n - 1) eval &= suff[i + 1];
    if (eval > maxim) {
      val = i;
      maxim = eval;
    }
  }

  cout << orig[val];
  for (int i = 0; i < n; i++) {
    if (val == i) continue;
    cout << " " << orig[i];
  }
  cout << endl;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
