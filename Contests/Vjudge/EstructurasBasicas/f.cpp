
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
  vector<set<int>> poss(26);
  for (int i = 0; i < s.size(); i++) {
    poss[s[i] - 'a'].insert(i);
  }

  int q;
  cin >> q;
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      cin >> pos;
      pos--;
      char c;
      cin >> c;
      poss[s[pos] - 'a'].erase(pos);
      poss[c - 'a'].insert(pos);
      s[pos] = c;
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int cnt = 0;
      for (int i = 0; i < 26; i++) {
        auto it = poss[i].lower_bound(l);
        if (it != poss[i].end() && (*it) <= r) cnt++;
      }
      cout << cnt << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}