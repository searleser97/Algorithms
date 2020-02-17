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
// 12
void _main(int tc) {
  li q, x;
  cin >> q >> x;
  set<li> myset;
  vector<li> v(x);

  rep(i, x) {
    v[i] = i;
    myset.insert(i);
  }

  rep(i, q) {
    li y;
    cin >> y;
    int mod = y % x;
    myset.erase(v[mod]);
    v[mod] += x;
    myset.insert(v[mod]);
    cout << (*myset.begin()) << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
