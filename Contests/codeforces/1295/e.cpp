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
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;

template <class T>
struct SegmentTree {
  T neutro = 1ll << 61;
  int N, H;
  vector<T> st, d;
  vector<bool> u;

  SegmentTree(int n, T val) : st(2 * n, val), d(n), u(n) {
    H = sizeof(int) * 8 - __builtin_clz(N = n);
  }

  inline T F(T a, T b) { return min(a, b); }

  void apply(int i, T val, int k) {
    st[i] += val;
    if (i < N) d[i] += val, u[i] = 1;
  }

  void calc(int i) {
    if (!u[i]) st[i] = F(st[i << 1], st[i << 1 | 1]);
  }

  void build() {
    for (int i = N - 1; i > 0; i--) calc(i);
  }

  void build(int p) {
    while (p > 1) p >>= 1, calc(p);
  }

  void push(int p) {
    for (int s = H, k = 1 << (H - 1); s > 0;
         s--, k >>= 1) {
      int i = p >> s;
      if (u[i]) {
        apply(i << 1, d[i], k);
        apply(i << 1 | 1, d[i], k);
        u[i] = 0, d[i] = 0;
      }
    }
  }

  void update(int l, int r, T val) {
    push(l += N);
    push(r += N);
    int ll = l, rr = r, k = 1;
    for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) apply(l++, val, k);
      if (~r & 1) apply(r--, val, k);
    }
    build(ll);
    build(rr);
  }

  T query(int l, int r) {
    push(l += N);
    push(r += N);
    T ans = neutro;
    for (; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = F(ans, st[l++]);
      if (~r & 1) ans = F(ans, st[r--]);
    }
    return ans;
  }

  T& operator[](int i) { return st[i + N]; }
};

void _main(int tc) {
  int n;
  cin >> n;
  vector<li> p(n), a(n), pos(n);
  SegmentTree<li> st(n, 0);

  rep(i, n) {
    cin >> p[i];
    pos[--p[i]] = i;
  }
  
  rep(i, n) {
    cin >> a[i];
    if (i) st[i] = a[i] + st[i - 1];
    else st[i] = a[i];
  }

  st.build();

  li ans = st.query(0, n - 2);
  
  rep(i, n) {
    st.update(0, pos[i] - 1, a[pos[i]]);
    st.update(pos[i], n - 1, -a[pos[i]]);
    ans = min(ans, st.query(0, n - 2));
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