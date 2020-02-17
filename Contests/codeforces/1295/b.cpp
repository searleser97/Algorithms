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
  int n, x;
  cin >> n >> x;
  string str;
  cin >> str;
  vector<int> bal(n + 1);
  int zeroes = 0, ones = 0;
  rep(i, n) {
    if (str[i] == '1') ones++;
    else zeroes++;
    bal[i + 1] = zeroes - ones;
  }

  if (bal[n] == 0) {
    forn(i, 1, bal.size()) {
      if (bal[i] == x) {
        cout << -1 << endl;
        return;
      }
    }
  }

  if (bal[n] == 0) {
    cout << 0 << endl;
    return;
  }

  int ans = 0;
  rep(i, n) {
    if (abs(x - bal[i]) % abs(bal[n]) == 0) {
      if ((x -  bal[i]) / bal[n] >= 0)
        ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}