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
  cin >> n >> m;
  vector<li> cost(n), rem(n);
  set<pair<int, int>> costset;

  for (int i = 0; i < n; i++) {
    cin >> rem[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> cost[i];
    costset.insert({cost[i], i});
  }

  for (int i = 0; i < m; i++) {
    li t, d, ans = 0;
    cin >> t >> d;
    t--;
    if (rem[t] >= d) {
      rem[t] -= d;
      ans = d * cost[t];
    } else {
      d -= rem[t];
      ans += cost[t] * rem[t];
      rem[t] = 0;

      while (true) { // if empty set, if has reached d
        if (costset.size() == 0) {
          ans = 0;
          break;
        }
        auto cheapestIt = costset.begin();
        auto cheapest = *cheapestIt;
        if (rem[cheapest.second] >= d) {
          rem[cheapest.second] -= d;
          ans += d * cost[cheapest.second];
          break;
        } else {
          d -= rem[cheapest.second];
          ans += rem[cheapest.second] * cost[cheapest.second];
          rem[cheapest.second] = 0;
          costset.erase(cheapestIt);
        }
      }
    }
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}