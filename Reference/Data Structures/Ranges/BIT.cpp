typedef int T;
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