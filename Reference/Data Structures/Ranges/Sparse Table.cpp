#include <bits/stdc++.h>

using namespace std;
// st = sparse table
typedef int T;

int MAXN = 100, N;
vector<vector<T>> st;
vector<T> arr;

void initVars() {
  st = vector<vector<T>>(MAXN, vector<T>(log2(MAXN) + 1));
  arr = vector<T>(MAXN);
}

static T F1(T a, T b) {
  // return min(a, b);
  return __gcd(a, b);
}

static T F2(T a, T b) {
  return a + b;
  // return a * b;
}

// O(NlgN)
void buildSparseTabe(T F(T, T)) {
  st[0] = arr;
  for (int i = 1; (1 << i) <= N; i++)
    for (int j = 0; j + (1 << i) <= N; j++) st[i][j] = F(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

// O(1)
T query(int L, int R) {
  int i = log2(R - L + 1);
  return F1(st[i][L], st[i][R + 1 - (1 << i)]);
}

// O(lgN)
T queryArith(int L, int R) {
  // Neutral Element
  T ans = 0;  // for sum
  // T ans = 1; for multiplication
  while (true) {
    int k = log2(R - L + 1);
    ans = F2(ans, st[k][L]);
    L += 1 << k;
    if (L > R) break;
  }
  return ans;
}
int main() {
  initVars();
  N = 9;
  arr = {7, 2, 3, 0, 5, 10, 3, 12, 18};
  buildSparseTabe(F1);

  cout << query(0, 2) << endl;
  cout << query(1, 3) << endl;
  cout << query(4, 5) << endl;

  initVars();
  N = 6;
  arr = {3, 7, 2, 5, 8, 9};
  buildSparseTabe(F2);
  cout << queryArith(0, 5) << endl;
  cout << queryArith(3, 5) << endl;
  cout << queryArith(2, 4) << endl;
  return 0;
}