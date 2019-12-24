// 4
// indeg0 = indegree 0
vector<int> vis, indegree, path;
vector<vector<int>> adj, toposorts;
deque<int> indeg0;
// 5
void init(int n) {
  adj.assign(n, vector<int>());
  vis.assign(n, 0);
  indegree = vis;
}
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  indegree[v]++;
}
// 19
// O(V!)
void dfs() {
  for (int i = 0; i < indeg0.size(); i++) {
    int u = indeg0.front();
    indeg0.pop_front();
    path.push_back(u);
    for (auto &v : adj[u])
      if (!--indegree[v]) indeg0.push_back(v);
    if (!indeg0.size()) toposorts.push_back(path);
    dfs();
    for (int v = adj[u].size() - 1; ~v; v--) {
      indegree[adj[u][v]]++;
      if (indeg0.back() == adj[u][v])
        indeg0.pop_back();
    }
    indeg0.push_back(u);
    path.pop_back();
  }
}
// 6
// O(V + V!)
void allToposorts() {
  for (int u = 0; u < adj.size(); u++)
    if (!indegree[u]) indeg0.push_back(u);
  dfs();
}