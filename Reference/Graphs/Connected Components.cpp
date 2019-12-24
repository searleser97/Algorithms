// 4
// comp = component
int compId;
vector<vector<int>> adj;
vector<int> getComp;
// 5
void init(int N) {
  adj.assign(N, vector<int>());
  getComp.assign(N, -1);
  compId = 0;
}
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
// 6
void dfsCC(int u, vector<int> &comp) {
  if (getComp[u] > -1) return;
  getComp[u] = compId;
  comp.push_back(u);
  for (auto &v : adj[u]) dfsCC(v, comp);
}
// 10
// O(N)
vector<vector<int>> connectedComponents() {
  vector<vector<int>> comps;
  for (int u = 0; u < adj.size(); u++) {
    vector<int> comp;
    dfsCC(u, comp);
    if (!comp.empty())
      comps.push_back(comp), compId++;
  }
  return comps;
}