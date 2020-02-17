#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define forr(_, x, n) for (int _ = x; ~_; _--)
// #define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
// #define forn(_, x, n) fos(_, x, n, 1)
// #define rep(_, n) forn(_, 0, n)
// #define fi first
// #define se second
// #define pb push_back
// #define pairii pair<int, int>
// typedef __int128_t lli;
// typedef long long int li;
// typedef long double ld;
// 12
void _main(int tc) {
  string n;
  cin >> n;
  if (n.back() == '0' || n.back() == '5') cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) _main(i + 1);
}