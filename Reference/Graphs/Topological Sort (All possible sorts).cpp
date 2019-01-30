// 4
// indeg0 = indegree 0
vector<int> vis, indegree, path;
vector<vector<int>> ady, toposorts;
deque<int> indeg0;
// 5
void initVars(int n) {
  ady.assign(n, vector<int>());
  vis.assign(n, 0);
  indegree = vis;
}
// 4
void addEdge(int u, int v) {
  ady[u].push_back(v);
  indegree[v]++;
}
// 19
// O(V!)
void dfs() {
  for (int i = 0; i < indeg0.size(); i++) {
    int u = indeg0.front();
    indeg0.pop_front();
    path.push_back(u);
    for (auto &v : ady[u])
      if (!--indegree[v]) indeg0.push_back(v);
    if (!indeg0.size()) toposorts.push_back(path);
    dfs();
    for (int v = ady[u].size() - 1; ~v; v--) {
      indegree[ady[u][v]]++;
      if (indeg0.back() == ady[u][v])
        indeg0.pop_back();
    }
    indeg0.push_back(u);
    path.pop_back();
  }
}
// 6
// O(V + V!)
void allToposorts() {
  for (int u = 0; u < ady.size(); u++)
    if (!indegree[u]) indeg0.push_back(u);
  dfs();
}