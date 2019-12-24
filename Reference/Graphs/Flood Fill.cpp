// 4
int n, m, oldColor = 0, color = 1;
vector<vector<int>> mat;
vector<vector<int>> movs = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// 9
void floodFill(int i, int j) {
  if (i >= mat.size() || i < 0 ||
      j >= mat[i].size() || j < 0 ||
      mat[i][j] != oldColor)
    return;
  mat[i][j] = color;
  for (auto move : movs)
    floodFill(i + move[1], j + move[0]);
}
// 5
void floodFill() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] == oldColor) floodFill(i, j);
}