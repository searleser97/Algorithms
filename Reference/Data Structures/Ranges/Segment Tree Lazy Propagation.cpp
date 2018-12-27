// st = segment tree, st[1] = root, H = height;
// u = updates, d = delayed updates
// neutro = operation neutral val
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
#include <bits/stdc++.h>
using namespace std;
typedef int T;
T neutro = 0;
int N, H;
vector<T> st, d;
vector<bool> u;

void initVars(int n) {
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

T kTimesF(T a, T k) {
  return a * k;  // sum
  // return a // min, max, gcd
  // return pow(a, k);  // multiplication
}

void calc(int i) {
  st[i] = F(st[i << 1], st[i << 1 | 1]);
}

void apply(int i, int val, int k) {
  st[i] += kTimesF(val, k);
  if (i < N) d[i] = val, u[i] = 1;
}

void build() {
  for (int i = N - 1; i > 0; i--) calc(i);
}

void push(int p) {
  for (int s = H, k = 1 << (H - 1); s > 0; s--, k >>= 1) {
    int i = p >> s;
    if (u[i]) {
      apply(i << 1, d[i], k);
      apply(i << 1 | 1, d[i], k);
      u[i] = 0;
    }
  }
}

// [l, r]
void modify(int l, int r, int val) {
  push(l += N);
  push(r += N);
  int cl = 0, cr = 0, k = 1;
  for (r++; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l - 1);
    if (cr) calc(r);
    if (l & 1) apply(l++, val, k), cl = 1;
    if (r & 1) apply(--r, val, k), cr = 1;
  }
  for (l--; r > 0; l >>= 1, r >>= 1) {
    if (cl) calc(l);
    if (cr && (!cl || l != r)) calc(r);
  }
}

// [l, r]
T query(int l, int r) {
  push(l += N);
  push(r += N);
  T ans = neutro;
  for (r++; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = F(ans, st[l++]);
    if (r & 1) ans = F(ans, st[--r]);
  }
  return ans;
}

void setValAt(T val, unsigned pos) {
  st[pos + N] = val;
}

T getValAt(unsigned pos) {
  return st[pos + N];
}

void printST() {
  for (auto i : st) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  initVars(16);
  for (int i = 0; i < 16; i++) setValAt(i, i);
  build();
  printST();
  modify(0, 15, 1);
  printST();
  cout << query(0, 15) << endl;
  printST();
  modify(4, 6, 0);
  printST();
  cout << query(4, 7) << endl;
  printST();
  return 0;
}