// sum of elements in range
int neutro = 0;

vector<int> arr;
vector<int> blks;
// 4
void initVars(int n) {
  arr.assign(n, neutro);
  blks.assign(sqrt(n), neutro);
}
// 5
void preprocess() {
  for (int i = 0, j = 0; i < arr.size(); i++) {
    if (i == blks.size() * j) j++;
    blks[j - 1] += arr[i];  // problem specific
  }
}
// 4
// problem specific
void update(int i, int val) {
  blks[i / blks.size()] += val - arr[i];
  arr[i] = val;
}
// 19
int query(int l, int r) {
  int sum = 0;
  int lblk = l / blks.size();
  if (l != blks.size() * lblk++)
    while (l < r && l != lblk * blks.size()) {
      sum += arr[l];  // problem specific
      l++;
    }

  while (l + blks.size() <= r) {
    sum += blks[l / blks.size()];  // problem specific
    l += blks.size();
  }
  while (l <= r) {
    sum += arr[l];  // problem specific
    l++;
  }
  return sum;
}
// 15
int main() {
  initVars(10);
  arr = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
  preprocess();
  for (int i = 0; i < blks.size() + 1; i++) cout << blks[i] << " ";
  // output: 8 11 15 10
  cout << endl;
  cout << query(3, 8) << " ";
  cout << query(1, 6) << " ";
  update(8, 0);
  cout << query(8, 8) << endl;
  // output: 26 21 0
  return 0;
}