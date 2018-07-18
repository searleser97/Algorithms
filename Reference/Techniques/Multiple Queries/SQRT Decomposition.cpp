// sum of elements in range
#include <bits/stdc++.h>

using namespace std;

int N, blksize;
int MAXN = 100, MAXSQR = (int)sqrt(MAXN);

vector<int> arr(MAXN);
vector<int> blks(MAXSQR + 1);

void preprocess() {
  blksize = sqrt(N);
  for (int i = 0, j = 0; i < N; i++) {
    if (i == blksize * j) j++;
    blks[j - 1] += arr[i];  // problem specific
  }
}

// problem specific
void update(int i, int val) {
  blks[i / blksize] += val - arr[i];
  arr[i] = val;
}

int query(int l, int r) {
  int sum = 0;
  int lblk = l / blksize;
  if (l != blksize * lblk++)
    while (l < r && l != lblk * blksize) {
      sum += arr[l];  // problem specific
      l++;
    }

  while (l + blksize <= r) {
    sum += blks[l / blksize];  // problem specific
    l += blksize;
  }
  while (l <= r) {
    sum += arr[l];  // problem specific
    l++;
  }
  return sum;
}

int main() {
  N = 10;
  arr = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
  preprocess();
  for (int i = 0; i < blksize + 1; i++)
    cout << blks[i] << " ";
  // 8 11 15 10
  cout << endl;
  cout << query(3, 8) << " ";
  cout << query(1, 6) << " ";
  update(8, 0);
  cout << query(8, 8) << endl;
  // 26 21 0
  return 0;
}