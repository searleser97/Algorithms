// 3
typedef long long int T;
T neutro = 0;
vector<T> bit1, bit2;
// 4
void initVars(int n) {
  bit1.assign(++n, neutro);
  bit2 = bit1;
}
// 5
// O(lg(N))
void update(vector<T> &bit, int i, T val) {
  for (i++; i < bit.size(); i += i & -i)
    bit[i] += val;
}
// 7
// O(lg(N)), [l, r]
void update(int l, int r, T val) {
  update(bit1, l, val);
  update(bit1, r + 1, -val);
  update(bit2, r + 1, val * r);
  update(bit2, l, -val * (l - 1));
}
// 6
// O(lg(N))
T query(vector<T> &bit, int i) {
  T ans = neutro;
  for (i++; i; i -= i & -i) ans += bit[i];
  return ans;
}
// 4
// O(lg(N))
T query(int i) {
  return query(bit1, i) * i + query(bit2, i);
}
// 4
// O(lg(N)), [l, r]
T query(int l, int r) {
  return query(r) - query(l - 1);
}