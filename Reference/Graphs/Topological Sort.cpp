int n;                    // max node id >= 0
vector<vector<int>> ady;  // ady.resize(n)
vector<int> vis;          // vis.resize(n)
vector<int> toposorted;

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
  for (int u = 0; u < n; u++)
    if (!vis[u])
      if (!toposort(u)) return false;
  return true;
}