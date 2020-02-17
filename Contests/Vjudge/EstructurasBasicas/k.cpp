
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
  int n, m;
  cin >> n;
  vector<int> boys(n);
  rep(i, n) {
    cin >> boys[i];
  }

  cin >> m;
  vector<int> girls(m);

  rep(i, m) {
    cin >> girls[i];
  }

  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());
  int ans = 0;
  rep(i, n) {
    rep(j, m) {
      if (abs(boys[i] - girls[j]) <= 1) {
        ans++;
        girls[j] = 2e9;
        break;
      }
    }
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