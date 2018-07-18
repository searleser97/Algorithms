#include <bits/stdc++.h>

using namespace std;
// st = segment tree
int MAXN = 100, N;
vector<int> st, arr;
typedef int T;

const T F(T a, T b);

void initVars() {
  st = vector<int>(2 * MAXN);
  arr = vector<int>(N);
}

int build() {
  copy(arr.begin(), arr.end(), st.begin() + N);
  for (int i = N - 1; i > 0; i--)
    st[i] = F(st[i << 1], st[i << 1 | 1]);
}

void updateNode(int i, T val) {
  for (st[i += N] = val; i > 1; i >>= 1)
    st[i >> 1] = F(st[i], st[i ^ 1]);
}

int main() {
  return 0;
}