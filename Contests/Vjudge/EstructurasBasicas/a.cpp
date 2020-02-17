
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

struct custom_hash {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};
// 12
void _main(int tc) {
  int n, k;
  cin >> n >> k;
  unordered_set<int, custom_hash> inque;
  deque<int> q;
  rep(i, n) {
    int id;
    cin >> id;
    if (inque.count(id)) {
      continue;
    }
    if (q.size() == k) {
      inque.erase(q.back());
      q.pop_back();
    }
    q.push_front(id);
    inque.insert(id);
  }

  cout << q.size() << endl;

  rep(i, q.size()) {
    if (i) cout << " ";
    cout << q[i];
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