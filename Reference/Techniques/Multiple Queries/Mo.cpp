// q = query
// qs = queries
// 3
struct Query {
  int l, r;
};

int blksize;
vector<Query> qs;
vector<int> arr;
// 4
void initVars(int N, int M) {
  arr = vector<int>(N);
  qs = vector<Query>(M);
}
// 4
bool cmp(Query &a, Query &b) {
  if (a.l == b.l) return a.r < b.r;
  return a.l / blksize < b.l / blksize;
}
// 27
void getResults() {
  blksize = (int)sqrt(arr.size());
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

    cout << "sum[" << L << ", " << R << "] = " << sum << endl;
  }
}
// 6
int main() {
  initVars(9, 2);
  arr = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  qs = {{0, 8}, {3, 5}};
  getResults();
}