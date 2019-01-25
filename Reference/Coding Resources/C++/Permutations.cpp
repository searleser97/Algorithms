// 10
typedef vector<int> T;  // typedef string T;

vector<T> permutations(T v) {
  vector<vector<int>> ans;
  sort(v.begin(), v.end());
  do
    ans.push_back(v);
  while (next_permutation(v.begin(), v.end()));
  return ans;
}