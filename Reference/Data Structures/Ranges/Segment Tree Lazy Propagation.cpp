// st = segment tree, st[1] = root, H = height of d
// u = updates, d = delayed updates
// neutro = operation neutral val
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
typedef int T;
T neutro = 0;
int N, H;
vector<T> st, d;
vector<bool> u;

void initVars(T n) {
  u.assign(N = n, 0);
  d.assign(n, neutro);
  st.assign(2 * n, neutro);
  H = sizeof(int) * 8 - __builtin_clz(n);
}

T F(T a, T b) {
  return a + b;
  // return __gcd(a, b);
  // return a * b;
  // return min(a, b);
}

void apply(int i, T val, int k) {
  st[i] = val * k; // sum
  // st[i] = val; // min, max, gcd
  // st[i] = pow(a, k); // multiplication
  if (i < N) d[i] = val, u[i] = 1;
}

void calc(int i) {
  if (!u[i]) st[i] = F(st[i << 1], st[i << 1 | 1]);
}
// O(2N)
void build() {
  for (int i = N - 1; i > 0; i--) calc(i);
}
// O(lg(N))
void build(int p) {
  while (p > 1) p >>= 1, calc(p);
}
// O(lg(N))
void push(int p) {
  for (int s = H, k = 1 << (H - 1); s > 0; s--, k >>= 1) {
    int i = p >> s;
    if (u[i]) {
      apply(i << 1, d[i], k);
      apply(i << 1 | 1, d[i], k);
      u[i] = 0, d[i] = neutro;
    }
  }
}
// O(lg(N)), [l, r]
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
// O(lg(2N)), [l, r]
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

void setValAt(T val, int i) {
  st[i + N] = val;
}

T getValAt(int i) {
  return st[i + N];
}