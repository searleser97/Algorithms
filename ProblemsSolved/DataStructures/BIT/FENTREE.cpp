#include <bits/stdc++.h>
using namespace std;
typedef long long int T;
T neutro = 0;
vector<T> bit;

void initVars(int n) {
  bit.assign(++n, neutro);
}

T F(T a, T b) {
  return a + b;
  // return a * b;
}
// Inverse of F
T I(T a, T b) {
  return a - b;
  // return a / b;
}
// O(N)
void build() {
  for (int i = 1; i < bit.size(); i++) {
    int j = i + (i & -i);
    if (j < bit.size()) bit[j] = F(bit[j], bit[i]);
  }
}
// O(lg(N))
void update(int i, T val) {
  for (i++; i < bit.size(); i += i & -i) bit[i] = F(bit[i], val);
}
// O(lg(N))
T query(int i) {
  T ans = neutro;
  for (i++; i > 0; i -= i & -i) ans = F(ans, bit[i]);
  return ans;
}
// O(lg(N)), [l, r]
T query(int l, int r) {
  return I(query(r), query(--l));
}

void setValAt(T val, int i) {
  bit[++i] = val;
}

int main() {
  int n;
  cin >> n;
  initVars(n);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    setValAt(val, i);
  }
  build();
  int q;
  cin >> q;
  while (q--) {
    char op;
    cin >> op;
    if (op == 'u') {
      int i;
      T x;
      cin >> i >> x;
      update(i - 1, x);
    }
    if (op == 'q') {
      int l, r;
      cin >> l >> r;
      cout << query(l - 1, r - 1) << endl;
    }
  }
  return 0;
}