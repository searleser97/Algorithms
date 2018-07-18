int n;                    // max node id >= 0
vector<vector<int>> ady;  // ady.resize(n)
vector<int> vis;          // vis.resize(n)
vector<vector<int>> cycles;
vector<int> cycle;
bool flag = false;
int rootNode = -1;

bool hasDirectedCycle(int u) {
  vis[u] = 1;
  for (auto &v : ady[u]) {
    if (v == u || vis[v] == 2) continue;
    if (vis[v] == 1 || hasDirectedCycle(v)) {
      if (rootNode == -1)
        rootNode = v, flag = true;
      if (flag) {
        cycle.push_back(u);
        if (rootNode == u) flag = false;
      }
      return true;
    }
  }
  vis[u] = 2;
  return false;
}

// O(N)
bool hasDirectedCycle() {
  vis.clear();
  for (int u = 0; u < n; u++)
    if (!vis[u]) {
      cycle.clear();
      if (hasDirectedCycle(u))
        cycles.push_back(cycle);
    }
  return cycles.size() > 0;
}