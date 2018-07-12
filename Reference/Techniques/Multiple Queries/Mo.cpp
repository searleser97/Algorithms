#include <bits/stdc++.h>

using namespace std;

// q = query
// qs = queries

struct Query {
  int l, r;
};

int N, M, blksize;
vector<Query> qs;
vector<int> arr;

void initVars() {
  qs = vector<Query>(M);
  arr = vector<int>(N);
}

bool cmp(Query &a, Query &b) {
  if (a.l == b.l) return a.r < b.r;
  return a.l / blksize < b.l / blksize;
}

void getResults() {
  blksize = (int)sqrt(N);
  sort(qs.begin(), qs.end(), cmp);
  int prevL = 0, prevR = -1;
  int sum = 0;
  for (auto &q : qs) {
    int L = q.l, R = q.r;
    while (prevL < L) {
      sum -= arr[prevL];  // problem specific
      prevL++;
    }
    while (prevL > L) {
      prevL--;
      sum += arr[prevL];  // problem specific
    }
    while (prevR < R) {
      prevR++;
      sum += arr[prevR];  // problem specific
    }
    while (prevR > R) {
      sum -= arr[prevR];  // problem specific
      prevR--;
    }

    cout << "sum[" << L << ", " << R
         << "] = " << sum << endl;
  }
}

int main() {
  arr = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  N = arr.size();
  qs = {{0, 8}, {3, 5}};
  M = qs.size();
  getResults();
}