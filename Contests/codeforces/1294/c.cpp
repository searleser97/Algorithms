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

typedef vector<li> V;


void _main(int tc) {
  li n;
  cin >> n;

  bool isPrime = true;
  li newN = 0, small = 0, large = 0;
  for (li i = 2; i * i <= n; i++)
    if (!(n % i)) {
      isPrime = false;
      small = i;
      if (i * i != n) {
        large = n / i;
      }
      break;
    }
  if (isPrime || large == 0) {
    cout << "NO" << endl;
    return;
  }

  newN = large;
  isPrime = true;
  li newSmall = 0, newLarge = 0;
  for (li i = 2; i * i <= newN; i++) {
    if (newN % i == 0 && i != small) {
      isPrime = false;
      newSmall = i;
      if (i * i != newN && (newN / i) != small) {
        newLarge = newN / i;
        break;
      }
    }
  }

  if (!isPrime && newLarge != 0) {
    cout << "YES" << endl;
    cout << small << " " << newSmall << " " << newLarge << endl;
    return;
  }

  newN = small;

  isPrime = true;
  newSmall = 0, newLarge = 0;
  for (li i = 2; i * i <= newN; i++) {
    if (newN % i == 0 && i != large) {
      isPrime = false;
      newSmall = i;
      if (i * i != newN && (newN / i) != large) {
        newLarge = newN / i;
        break;
      }
    }
  }

  if (isPrime || large == 0) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  cout << large << " " << newSmall << " " << newLarge << endl;
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  // _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
