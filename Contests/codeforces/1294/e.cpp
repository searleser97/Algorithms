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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  
  li ans = 0;
  rep(j, m) {
    vector<int> cnt(n);
    rep(i, n) {
      if (a[i][j] % m == j) {
        int pos = a[i][j] / m;
        if (pos < n) cnt[(i - pos + n) % n]++;
      }
    }
    int cur = n - cnt[0];
    forn(i, 1, n) cur = min(cur, n - cnt[i] + i);
    ans += cur;
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
 
