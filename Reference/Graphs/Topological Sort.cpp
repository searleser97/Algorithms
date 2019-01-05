// vis = visited
vector<vector<int>> ady;
vector<int> vis, toposorted;

void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  toposorted.clear();
}
// returns false if there is a cycle
bool toposort(int u) {
  vis[u] = 1;
  for (auto &v : ady[u]) {
    if (v == u || vis[v] == 2) continue;
    if (vis[v] == 1 || !toposort(v)) return false;
  }
  vis[u] = 2;
  toposorted.push_back(u);
  return true;
}
// O(N)
bool toposort() {
  vis.clear();
  for (int u = 0; u < ady.size(); u++)
    if (!vis[u] && !toposort(u)) return false;
  return true;
}