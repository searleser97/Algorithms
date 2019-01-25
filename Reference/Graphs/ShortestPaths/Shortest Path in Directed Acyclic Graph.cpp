// 6
// vis = visited
typedef int T;
vector<vector<int>> ady;
vector<int> vis, toposorted;
int INF = 1 << 30;
unordered_map<int, unordered_map<int, T>> weight;
// 6
void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  toposorted.clear();
  weight.clear();
}
// 4
void addEdge(int u, int v, int w) {
  ady[u].push_back(v);
  weight[u][v] = w;
}
// 12
// returns false if there is a cycle
// O(N)
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
// 14
// O(N)
vector<T> sssp(int s) {
  vector<T> dist(ady.size(), INF);
  dist[s] = 0;
  toposort(s);
  while (toposorted.size()) {
    int u = toposorted.back();
    toposorted.pop_back();
    for (auto &v : ady[u]) {
      T w = weight[u][v], d = dist[u] + w;
      if (d < dist[v]) dist[v] = d;
    }
  }
  return dist;
}