// st = segment tree, st[1] = root, H = height of d;
// u = updates, d = delayed updates
// neutro = operation neutral val
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
#include <bits/stdc++.h>
using namespace std;
typedef long long int T;
long long int INF = 1LL << 60;
T neutro = INF;
int N, H;
vector<T> st, d;
vector<bool> u;

void initVars(T n) {
  u.assign(N = n, 0);
  d.assign(n, 0LL);
  st.assign(2 * n, 0LL);
  H = sizeof(int) * 8 - __builtin_clz(n);
}

T F(T a, T b) {
  // return a + b;
  // return __gcd(a, b);
  // return a * b;
  return min(a, b);
}

T kTimesF(T a, T k) {
  // return a * k;  // sum
  return a;  // min, max, gcd
  // return pow(a, k);  // multiplication
}

void apply(int i, T val, int k) {
  st[i] += kTimesF(val, k);
  if (i < N) d[i] += val, u[i] = 1;
}

void calc(int i) {
  if (!u[i]) st[i] = F(st[i << 1], st[i << 1 | 1]);
}

// O(2N)
void build() {
  for (int i = N - 1; i > 0; i--) calc(i);
}

void build(int p) {
  while (p > 1) p >>= 1, calc(p);
}

void push(int p) {
  for (int s = H, k = 1 << (H - 1); s > 0; s--, k >>= 1) {
    int i = p >> s;
    if (u[i]) {
      apply(i << 1, d[i], k);
      apply(i << 1 | 1, d[i], k);
      u[i] = 0, d[i] = 0LL;
    }
  }
}

// [l, r] O(lg(2N))
void modify(int l, int r, T val) {
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

// [l, r] O(lg(2N))
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

void setValAt(T val, int pos) {
  st[pos + N] = val;
}

T getValAt(int pos) {
  return st[pos + N];
}

string input() {
  string ans;
  getline(cin, ans);
  return ans;
}

vector<int> split(string str, char token) {
  stringstream test(str);
  string seg;
  vector<int> seglist;
  while (getline(test, seg, token)) seglist.push_back(stoi(seg));
  return seglist;
}

int main() {
  int n, m;
  n = stoi(input());
  initVars(n);
  vector<int> in = split(input(), ' ');
  for (int i = 0; i < n; i++) {
    setValAt(in[i], i);
  }
  build();
  m = stoi(input());
  while (m--) {
    vector<int> in = split(input(), ' ');
    if (in.size() == 2) {
      if (in[0] <= in[1])
        cout << query(in[0], in[1]) << endl;
      else {
        cout << min(query(0, in[1]), query(in[0], N - 1)) << endl;
      }
    } else {
      if (in[0] <= in[1])
        modify(in[0], in[1], in[2]);
      else {
        modify(0, in[1], in[2]);
        modify(in[0], N - 1, in[2]);
      }
    }
  }
  return 0;
}