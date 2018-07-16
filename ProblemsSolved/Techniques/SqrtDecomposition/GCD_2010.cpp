#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// complexity: O(Q/2 + (Q/2)*(blksize + Q/blksize))

int MAXN = 500000, index = 0;
vector<int> arr(MAXN);
// int blksize = sqrt(MAXN);
// exceptional case where blksize
// of sqrt(N) is not optimal :'D
int blksize = 100;
vector<int> blks(MAXN / blksize);
unordered_map<int, int> getPos, rep;
int ans;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void totalGCD() {
  ans = 0;
  int limit = blksize;
  if (index >= blksize)
    limit = (index / blksize) + 1;
  for (int i = 0; i < limit; i++) {
    ans = gcd(ans, blks[i]);
    if (ans == 1) break;
  }
}

void blkGCD(int blk) {
  int start = blk * blksize;
  int limit = (blk + 1) * blksize;
  blks[blk] = 0;
  for (int i = start; i < limit; i++) {
    if (rep[arr[i]])
      blks[blk] = gcd(blks[blk], arr[i]);
    if (blks[blk] == 1) break;
  }
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  int N;
  // cin >> N;
  scanf(" %d", &N);
  while (N--) {
    char o;
    int x;
    // cin >> o >> x;
    scanf(" %c %d", &o, &x);
    int blk;
    if (o == '+') {
      if (rep.count(x))
        blk = getPos[x] / blksize;
      else {
        blk = index / blksize;
        arr[index] = x;
        getPos[x] = index++;
      }
      rep[x]++;
      blks[blk] = gcd(blks[blk], x);
      ans = gcd(ans, x);
    } else {
      rep[x]--;
      blk = getPos[x] / blksize;
      blkGCD(blk);
      totalGCD();
    }
    if (ans)
      // cout << ans << endl;
      printf("%d\n", ans);
    else
      // cout << 1 << endl;
      printf("1\n");
  }
  return 0;
}