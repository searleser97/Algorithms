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
  string s;
  cin >> s;
  int onesStart1 = -1, onesStart2 = -1;
  int cnt = 0;

  rep(i, s.size()) {
    if (s[i] == '1') {
      onesStart1 = i;
      break;
    }
  }

  if (onesStart1 == -1) {
    cout << 0 << endl;
    return;
  }

  for (int i = s.size() - 1; ~i; i--) {
    if (s[i] == '1') {
      onesStart2 = i;
      break;
    }
  }

  for (int i = onesStart1 + 1; i < onesStart2; i++) {
    if (s[i] == '0') cnt++;
  }

  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}