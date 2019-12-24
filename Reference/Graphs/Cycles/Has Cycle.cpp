// 3
vector<vector<int>> adj;
vector<int> vis;
bool isDirected = false;
// 4
void init(int N) {
  adj.assign(N, vector<int>());
  vis.assign(N, 0);
}
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  if (!isDirected) adj[v].push_back(u);
}
// 10
bool hasCycle(int u, int prev) {
  vis[u] = 1;
  for (auto &v : adj[u])
    if (v != u && vis[v] != 2 &&
        (isDirected || v != prev) &&
        (vis[v] || hasCycle(v, u)))
      return true;
  vis[u] = 2;
  return false;
}
// 5
// O(N)
bool hasCycle() {
  for (int u = 0; u < adj.size(); u++)
    if (!vis[u] && hasCycle(u, -1)) return true;
}