
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
  cin >> n;
  multiset<int> q;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
    v[i] = -v[i];
  }
  cin >> k;
  rep(i, k) {
    q.insert(v[i]);
  }
  cout << -(*q.begin());
  for (int i = k; i < v.size(); i++) {
    q.erase(q.find(v[i - k]));
    q.insert(v[i]);
    cout << " ";
    cout << -(*q.begin());
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