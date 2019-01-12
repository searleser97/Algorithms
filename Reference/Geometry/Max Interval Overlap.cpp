// 2
typedef long long int T;
typedef pair<T, T> Interval;
// 13
// O(N * lg(N))
pair<int, T> maxOverlap(vector<Interval> &arr) {
  map<T, int> m;
  int maxI = 0, curr = 0;
  T idx = -1LL;
  for (auto &i : arr) m[i.first]++, m[i.second + 1]--;
  for (auto &p : m) {
    curr += p.second;
    if (curr > maxI) maxI = curr, idx = p.first;
  }
  return {maxI, idx};
}
// 15
// O(MaxPoint) maxPoint < vector::max_size 
pair<int, int> maxOverlap(vector<Interval> &arr) {
  T maxPoint = 0;
  for (auto &i : arr)
    if (i.second > maxPoint) maxPoint = i.second;
  vector<int> x(maxPoint + 2);
  for (auto &i : arr) x[i.first]++, x[i.second + 1]--;
  int maxI = 0, curr = 0;
  T idx = -1LL;
  for (int i = 0; i < x.size(); i++) {
    curr += x[i];
    if (curr > maxI) maxI = curr, idx = i;
  }
  return {maxI, idx};
}