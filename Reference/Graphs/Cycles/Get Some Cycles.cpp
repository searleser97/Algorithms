// at least detects one cycle per component
vector<vector<int>> ady, cycles;
vector<int> vis, cycle;
bool flag = false, isDirected = false;
int root = -1;

void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  cycles.clear();
  root = -1, flag = false;
}

bool hasCycle(int u, int prev) {
  vis[u] = 1;
  for (auto &v : ady[u]) {
    if (v == u || vis[v] == 2 || (!isDirected && v == prev)) continue;
    if (flag) {
      if (!vis[v]) hasCycle(v, u);
      continue;
    }
    if (vis[v] || hasCycle(v, u)) {
      if (root == -1) root = v, flag = true;
      cycle.push_back(u);
      if (root == u) flag = false, root = -1, cycles.push_back(cycle), cycle.clear();
    }
  }
  vis[u] = 2;
  return flag;
}
// O(N)
bool hasCycle() {
  for (int u = 0; u < ady.size(); u++)
    if (!vis[u]) cycle.clear(), hasCycle(u, -1);
  return cycles.size() > 0;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  if (!isDirected) ady[v].push_back(u);
}