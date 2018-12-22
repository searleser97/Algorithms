// st = segment tree. st[1] = root, h = height;
// neutro = operation neutral value, d = delayed
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
#include <bits/stdc++.h>
using namespace std;
typedef int T;
T neutro = 0;
int N, h;
vector<T> st, arr, d;
vector<bool> b;

void initVars(int n) {
  b.assign(N = n, 0);
  d.assign(n, neutro);
  arr.assign(n, neutro);
  st.assign(2 * n, neutro);
  h = sizeof(int) * 8 - __builtin_clz(n);
}

T F(T a, T b) {
  return a + b;
  // return __gcd(a, b);
  // return a * b;
  // return min(a, b);
}

T kTimesF(T a, T k) {
  return a * k;
}

void calc(int p, int k) {
  if (!b[p])
    st[p] = F(st[p << 1], st[p << 1 | 1]);
  else
    st[p] = kTimesF(d[p], k);
}

void apply(int p, int value, int k) {
  st[p] = kTimesF(value, k);
  if (p < N) d[p] = value, b[p] = 1;
}

void build() {
  copy(arr.begin(), arr.end(), st.begin() + N);
  for (int i = N - 1; i > 0; i--) st[i] = F(st[i << 1], st[i << 1 | 1]);
}

// [l, r]
void push(int l, int r) {
  int s = h, k = 1 << (h - 1);
  for (l += N, r += N - 1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i)
      if (b[i]) {
        apply(i << 1, d[i], k);
        apply(i << 1 | 1, d[i], k);
        b[i] = 0;
      }
}

// [l, r)
void modify(int l, int r, int value) {
  push(l, l + 1);
  push(r - 1, r);
  int cl = 0, cr = 0, k = 1;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l - 1, k);
    if (cr) calc(r, k);
    if (l & 1)
      apply(l++, value, k), cl = 1;
    if (r & 1)
      apply(--r, value, k), cr = 1;
  }
  for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l, k);
    if (cr && (!cl || l != r)) calc(r, k);
  }
}

// [l, r)
T query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  T ans = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = F(ans, st[l++]);
    if (r & 1) ans = F(ans, st[--r]);
  }
  return ans;
}

int main() {
  initVars(9);
  arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  build();
  for (auto i : st) {
    cout << i << " ";
  }
  cout << endl;
  modify(2, 6, 0);
  cout << query(2, 6) << endl;
  cout << query(3, 4) << endl;
  for (auto i : st) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}