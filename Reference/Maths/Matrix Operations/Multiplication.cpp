// 13
typedef int T;
typedef vector<vector<T>> Matrix;

// O(N^3)
Matrix multiply(Matrix a, Matrix b) {
  if (a[0].size() != b.size()) return {};
  Matrix ans(a.size(), vector<T>(b[0].size()));
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b[i].size(); j++)
      for (int k = 0; k < b.size(); k++)
        ans[i][j] += a[i][k] * b[k][j];
  return ans;
}