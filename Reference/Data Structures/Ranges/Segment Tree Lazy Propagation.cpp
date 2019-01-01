// st = segment tree, st[1] = root, H = height;
// u = updates, d = delayed updates
// neutro = operation neutral val
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
#include <bits/stdc++.h>
using namespace std;
typedef long long int T;
T neutro = 0LL;
int N, H;
vector<T> st, d;
vector<bool> u;

void initVars(T n) {
  u.assign(N = n, 0);
  d.assign(n, neutro);
  st.assign(2 * n, neutro);
  H = sizeof(int) * 8 - __builtin_clz(2 * n - 1);
}

T F(T a, T b) {
  // return a + b;
  return __gcd(a, b);
  // return a * b;
  // return min(a, b);
}

T kTimesF(T a, T k) {
  // return a * k;  // sum
  return a; // min, max, gcd
  // return pow(a, k);  // multiplication
}

void calc(int i) {
  if (!u[i]) st[i] = F(st[i << 1], st[i << 1 | 1]);
}

void apply(int i, T val, int k) {
  st[i] = kTimesF(val, k);
  if (i < N) d[i] = val, u[i] = 1;
}

// O(2N)
void build() {
  for (int i = N - 1; i > 0; i--) calc(i);
}

void build(int p) {
  while (p > 1) {
    p >>= 1, calc(p);
  }
}

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

// [l, r] O(lg(2N))
void modify(int l, int r, T val) {
  push(l += N);
  push(r += N);
  int l0 = l, r0 = r, k = 1;
  for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1) apply(l++, val, k);
    if (~r & 1) apply(r--, val, k);
  }
  build(l0);
  build(r0);
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

int MAXN = 500000;

unordered_map<int, int> getPos, rep;
int ans, ind = 0;

int main() {
  int q;
  scanf(" %d", &q);
  initVars(MAXN);
  for (int h = 0; h < q; h++) {
    char o;
    int x, pos;
    scanf(" %c %d", &o, &x);
    if (o == '+') {
      if (getPos.count(x))
        pos = getPos[x];
      else {
        pos = ind++;
        getPos[x] = pos;
      }
      if (!rep[x]++)
        modify(pos, pos, x);
    } else {
      if (!--rep[x])
        modify(getPos[x], getPos[x], neutro);
    }
    ans = st[1];
    if (ans)
      printf("%d\n", ans);
    else
      printf("1\n");
  }
  return 0;
}

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     long long int n, C;
//     cin >> n >> C;
//     initVars(n);
//     while (C--) {
//       long long int opc, p, q;
//       T val;
//       cin >> opc >> p >> q;
//       if (q < p) swap(p, q);
//       if (q > N) q = N;
//       if (opc) {
//         cout << query(p - 1, q - 1) << '\n';
//       } else {
//         cin >> val;
//         modify(p - 1, q - 1, val);
//       }
//     }
//   }
//   return 0;
// }