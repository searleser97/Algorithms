#include <bits/stdc++.h>
using namespace std;
typedef long long int T;
T neutro = 0;
vector<T> bit1, bit2;

void initVars(int n) {
  bit1.assign(++n, neutro);
  bit2 = bit1;
}

// O(lg(N))
void update(vector<T> &bit, int i, T val) {
  for (i++; i < bit.size(); i += i & -i) bit[i] += val;
}
// O(lg(N))
void update(int l, int r, T val) {
  update(bit1, l, val);
  update(bit1, r + 1, -val);
  update(bit2, r + 1, val * r);
  update(bit2, l, -val * (l - 1));
}
// O(lg(N))
T query(vector<T> &bit, int i) {
  T ans = neutro;
  for (i++; i; i -= i & -i) ans += bit[i];
  return ans;
}
// O(lg(N))
T query(int i) {
  return query(bit1, i) * i + query(bit2, i);
}
// O(lg(N))
T query(int l, int r) {
  return query(r) - query(l - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, C;
    cin >> n >> C;
    initVars(n);
    while (C--) {
      long long int opc, p, q;
      T val;
      cin >> opc >> p >> q;
      if (q < p) swap(p, q);
      if (q > n) q = n;
      if (opc) {
        cout << query(p - 1, q - 1) << '\n';
      } else {
        cin >> val;
        update(p - 1, q - 1, val);
      }
    }
  }
  return 0;
}