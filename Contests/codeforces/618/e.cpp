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
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;


double query(int l, int r, vector<int>& acum) {
  if (l == 0) return (double) acum[r] / (double) (r + 1);
  return (double)(acum[r] - acum[l - 1]) / (double) (r - l + 1);
}

void _main(int tc) {
  int n;
  cin >> n;
  vector<int> acum(n);
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
    if (i)
      acum[i] = v[i] + acum[i - 1];
    else
      acum[i] = v[i];
  }

  int j = n - 1;
  vector<pair<int, double>> ans(n);
  vector<int> indexes;
  rep(i, n) indexes[i] = i;

  while (true) {
    vector<int> newindexes;
    for (int ind = n - 2; ~ind; ind--) {
      if (v[ind] < v[ind + 1]) {
        ans[ind + 1] = {j, query(ind + 1, j, acum)};
        newindexes.pb(ind + 1);
        j = ind;
      }
    }
    indexes = newindexes;
  }

  ans[0] = {j, query(0, j, acum)};

  // rep(i, n) {
  //   cerr(i << " "  << ans[i].fi << " " << ans[i].se) << endl;
  // }

  for (int i = 0; i < n;) {
    if (ans[i].fi - i + 1 > 0)
    rep(j, ans[i].fi - i + 1) {
      cout << fixed << setprecision(9) << ans[i].se << endl;
    }
    i = ans[i].fi + 1;
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
