
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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> tb(n);

  for(int i = 0; i < n; i++) {
    int t, b;
    cin >> tb[i].second >> tb[i].first;
  }

  sort(tb.begin(), tb.end());
  
  set<pair<int, int>> s;
  li sum = 0, ans = 0;
  
  for (int i = n - 1; ~i; i--) {
    if (s.size() == k) {
      auto it = s.begin();
      sum -= (*it).first;
      s.erase(it);
    }
    int currBeauty = tb[i].first;
    int ithLength = tb[i].second;
    s.insert({ithLength, i});
    sum += ithLength;
    ans = max(ans, sum * currBeauty);
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