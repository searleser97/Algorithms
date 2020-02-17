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

void _main(int tc) {
  int n;
  cin >> n;
  n <<= 1;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  int ans = 0;
  ans = abs(v[(n >> 1) - 1] - v[(n >> 1)]);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}
