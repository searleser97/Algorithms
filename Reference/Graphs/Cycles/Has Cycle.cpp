vector<vector<int>> ady;
vector<int> vis;
bool isDirected = false;
// 4
void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
}
// 8
bool hasCycle(int u, int prev) {
  vis[u] = 1;
  for (auto &v : ady[u])
    if (v != u && vis[v] != 2 && (isDirected || v != prev) && (vis[v] || hasCycle(v, u))) return true;
  vis[u] = 2;
  return false;
}
// 5
// O(N)
bool hasCycle() {
  for (int u = 0; u < ady.size(); u++)
    if (!vis[u] && hasCycle(u, -1)) return true;
}
// 4
void addEdge(int u, int v) {
  ady[u].push_back(v);
  if (!isDirected) ady[v].push_back(u);
}