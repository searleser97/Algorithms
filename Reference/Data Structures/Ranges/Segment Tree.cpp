// st = segment tree. st[1] = root;
// neutro = operation neutral value
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
int MAXN = 500000, N;
vector<int> st, arr;
typedef int T;
const T neutro = 0;

void initVars() {
  st = vector<int>(2 * MAXN, neutro);
}

const T F(T a, T b) {
  // return a + b;
  return __gcd(a, b);
  // return a * b;
  // return min(a, b);
}

// O(2N)
int build() {
  copy(arr.begin(), arr.end(), st.begin() + N);
  for (int i = N - 1; i > 0; i--)
    st[i] = F(st[i << 1], st[i << 1 | 1]);
}

// O(lg(2N))
void updateNode(int i, T val) {
  for (st[i += N] = val; i > 1; i >>= 1)
    st[i >> 1] = F(st[i], st[i ^ 1]);
}

// O(3N), [l, r)
void updateRange(int l, int r, T val) {
  for (int i = l; i < r; i++)
    arr[i] = val;
  build();
}

// O(lg(2N)), [l, r)
T query(int l, int r) {
  int ans = neutro;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = F(ans, st[l++]);
    if (r & 1) ans = F(ans, st[--r]);
  }
  return ans;
}