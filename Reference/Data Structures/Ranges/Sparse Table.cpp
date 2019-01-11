// st = sparse table, Arith = Arithmetic
typedef int T;
int neutro = 0;
vector<vector<T>> st;
// 6
T F(T a, T b) {
  // return min(a, b);
  return __gcd(a, b);
  // return a + b; // Arith
  // return a * b; // Arith
}
// 7
// O(Nlg(N))
void build(vector<T> &arr) {
  st.assign(log2(arr.size()), vector<T>(arr.size()));
  st[0] = arr;
  for (int i = 1; (1 << i) <= arr.size(); i++)
    for (int j = 0; j + (1 << i) <= arr.size(); j++) st[i][j] = F(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
// 5
// O(1), [l, r]
T query(int l, int r) {
  int i = log2(r - l + 1);
  return F(st[i][l], st[i][r + 1 - (1 << i)]);
}
// 11
// O(lg(N)), [l, r]
T queryArith(int l, int r) {
  T ans = neutro;
  while (true) {
    int k = log2(r - l + 1);
    ans = F(ans, st[k][l]);
    l += 1 << k;
    if (l > r) break;
  }
  return ans;
}