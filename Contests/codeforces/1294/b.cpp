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
  int n;
  cin >> n;
  vector<pairii> v(n + 1);
  rep(i, n) {
  	cin >> v[i].first >> v[i].second;
  }
  v[n].first = 0, v[n].second = 0; // inserting (0, 0) coordinate to array.

  sort(v.begin(), v.end(), [] (pairii &a, pairii& b) {
  	if (a.first == b.first) return a.second < b.second; // sorting firt by X then by Y.
  	return a.first < b.first;
  });

  string ans;
  bool possible = true;

  rep(i, n) {
  	if (v[i + 1].first >= v[i].first && v[i + 1].second >= v[i].second) { // if the next point is to the right and or UP.
  		int rightIts = (v[i + 1].first - v[i].first); // iterations for R
  		int upIts = (v[i + 1].second - v[i].second); // iterations for U
  		rep(i, rightIts) {
  			ans += "R";
  		}
  		rep(i, upIts) {
  			ans += "U";
  		}	
  		continue;
  	}
  	possible = false;
  	break;
  }
  if (!possible) {
  	cout << "NO" << endl;
  } else {
  	cout << "YES" << endl;
  	cout << ans << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
