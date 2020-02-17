// 20
/****************************************************
https://searleser97.gitlab.io/algorithms/template.cpp
****************************************************/

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
  int n;
  cin >> n;
  vector<int> vv(n), negsPos;
  rep(i, n) {
    cin >> vv[i];
    
  }

  vector<int> v;
  for (int i = 0; i < n;) {
    v.pb(vv[i]);
    if (vv[i] != -1) {
      i++;
      continue;
    }
    while (vv[i] == -1) i++;
  }

  if (v.size() == 1) {
    cout << 0 << " " << 0 << endl;
    return;
  }
  int minim = 1 << 30, maxim = -1e9;

  rep(i, v.size()) {
    if (v[i] == -1) {
      if (i > 0) {
        maxim = max(maxim, v[i - 1]);
        minim = min(minim, v[i - 1]);
      }
      if (i < v.size() - 1) {
        maxim = max(maxim, v[i + 1]);
        minim = min(minim, v[i + 1]);
      }
    }
  }

  int ans = minim + (maxim - minim) / 2;

  rep(i, v.size()) {
    if (v[i] == -1) v[i] = ans;
  }
  int minm = -1e9;
  for (int p = 1; p < v.size(); p++) {
    minm = max(minm, abs(v[p] - v[p - 1]));
  }

  cout << minm << " " << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}