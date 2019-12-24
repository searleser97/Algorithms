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

T invCount(vector<T> &a) {
  initVars(a.size());
  unordered_map<int, T> m;
  int c = 0;
  vector<T> b = a;
  sort(b.begin(), b.end());
  for (T i : b) m[i] = c++;
  for (int i = 0; i < a.size(); i++) a[i] = m[a[i]];
  T count = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    count += query(a[i] - 1);
    update(a[i], 1);
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<T> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << invCount(a) << endl;
  }
  return 0;
}