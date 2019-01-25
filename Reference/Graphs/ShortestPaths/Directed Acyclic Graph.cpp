// 3
// vis = visited
vector<vector<int>> ady;
vector<int> vis, toposorted;
// 5
void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  toposorted.clear();
}
// 11
// returns false if there is a cycle
bool toposort(int u) {
  vis[u] = 1;
  for (auto &v : ady[u])
    if (v != u && vis[v] != 2 &&
        (vis[v] || !toposort(v)))
      return false;
  vis[u] = 2;
  toposorted.push_back(u);
  return true;
}

void addEdge(int u, int v) { ady[u].push_back(v); }

vector<T> SSSP(int s) {
  
}