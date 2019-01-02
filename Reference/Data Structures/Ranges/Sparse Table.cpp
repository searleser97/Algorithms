// st = sparse table, Arith = Arithmetic
typedef int T;
int neutro = 0;
vector<vector<T>> st;

T F(T a, T b) {
  // return min(a, b);
  return __gcd(a, b);
  // return a + b; // Arith
  // return a * b; // Arith
}

// O(NlgN)
void build(vector<T> &arr) {
  st.assign(ceil(log2(arr.size())), vector<T>(arr.size()));
  st[0] = arr;
  for (int i = 1; (1 << i) <= arr.size(); i++)
    for (int j = 0; j + (1 << i) <= arr.size(); j++) st[i][j] = F(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

// O(1)
T query(int L, int R) {
  int i = log2(R - L + 1);
  return F(st[i][L], st[i][R + 1 - (1 << i)]);
}

// O(lgN)
T queryArith(int L, int R) {
  T ans = neutro;
  while (true) {
    int k = log2(R - L + 1);
    ans = F(ans, st[k][L]);
    L += 1 << k;
    if (L > R) break;
  }
  return ans;
}