// 11
typedef int T;
typedef vector<vector<T>> Matrix;

// O(N * M)
Matrix add(Matrix a, Matrix b) {
  Matrix ans(a.size(), vector<T>(a[0].size()));
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++)
      ans[i][j] = a[i][j] + b[i][j];
  return ans;
}