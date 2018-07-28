#include <bits/stdc++.h>

using namespace std;
// st = segment tree
// neutro = operation neutral value
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
int MAXN = 500000, N;
vector<int> st, arr;
typedef int T;
T neutro = 0;

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

void updateRange();

// O(lg(2N)), [l, r)
T query(int l, int r) {
  int ans = neutro;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = F(ans, st[l++]);
    if (r & 1) ans = F(ans, st[--r]);
  }
  return ans;
}

unordered_map<int, int> getPos, rep;
int ans, ind = 0;

int main() {
  scanf(" %d", &N);
  initVars();
  for (int h = 0; h < N; h++) {
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
        updateNode(pos, x);
    } else {
      if (!--rep[x])
        updateNode(getPos[x], neutro);
    }
    ans = st[1];
    if (ans)
      printf("%d\n", ans);
    else
      printf("1\n");
  }
  return 0;
}