// 4
// st = segment tree. st[1] = root;
// neutro = operation neutral value
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
// 5
template <class T>
struct SegmentTree {
  T neutro = 0;
  int N;
  vector<T> st;
  // 3
  SegmentTree(int n) : st(2 * n, neutro), N(n) {}
  // 6
  T F(T a, T b) {
    return a + b;
    // return __gcd(a, b);
    // return a * b;
    // return min(a, b);
  }
  // 4
  // O(2N)
  void build() {
    for (int i = N - 1; i > 0; i--)
      st[i] = F(st[i << 1], st[i << 1 | 1]);
  }
  // 4
  // O(lg(2N))
  void update(int i, T val) {
    for (st[i += N] = val; i > 1; i >>= 1)
      st[i >> 1] = F(st[i], st[i ^ 1]);
  }
  // 4
  // O(3N), [l, r]
  void update(int l, int r, T val) {
    for (l += N, r += N; l <= r; l++) st[l] = val;
    build();
  }
  // 9
  // O(lg(2N)), [l, r]
  T query(int l, int r) {
    T ans = neutro;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = F(ans, st[l++]);
      if (~r & 1) ans = F(ans, st[r--]);
    }
    return ans;
  }
  // 2
  void setValAt(T val, int i) { st[i + N] = val; }
};