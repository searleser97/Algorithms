
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
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
  }

  unordered_map<int, int> um;

  int l = 0;
  for(int i = 0; i < n; i++) {
    if (um.size() < k) {
      um[v[i]]++;
    }
    if (um.size() == k) {
      while (true) {
        if (um.count(v[l])) {
          if ((--um[v[l]]) == 0) um.erase(v[l]);
          if (um.size() == k) l++;
          if (um.size() < k) break;
        } else
          break;
      }
      cout << l + 1 << " " << i + 1 << endl;
      return;
    }
  }
  cout << -1 << " " << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}