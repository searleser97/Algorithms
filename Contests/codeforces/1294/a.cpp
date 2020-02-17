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
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  vector<int> v = {a, b, c};
  int small = min(min(a, b), c);
  int large = max(max(a, b), c);
  int mid = -1;
  bool smallpassed = 0, largepassed = 0;
  rep(i, 3) {
    if (v[i] == small && smallpassed) {
      mid = small;
      break;
    }
    if (v[i] == large && largepassed) {
      mid = large;
      break;
    }
  	if (v[i] == small) {
      smallpassed = true;
      continue;
    }
    if (v[i] == large) {
      largepassed = true;
      continue;
    }
    mid = v[i];
    break;
  }

  if (mid == -1) {

  }

  // cout << small << " " << mid << " " << large << endl;
  // small reaches middle
  if (n < (mid - small)) {
  	cout << "NO" << endl;
    return;
  }
  n -= (mid - small);

  // mid reaches large
  li gdiff = (large - mid);
  if (n < (2 * gdiff)) {
    cout << "NO" << endl;
    return;
  }

  n -= 2 * gdiff;

  if (n % 3 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
