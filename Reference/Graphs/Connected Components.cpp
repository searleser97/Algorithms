// comp = component
int compId;
vector<vector<int>> ady;
vector<int> getComp;
// 5
void initVars(int N) {
  ady.assign(N, vector<int>());
  getComp.assign(N, -1);
  compId = 0;
}
// 6
void dfsCC(int u, vector<int> &comp) {
  if (getComp[u] > -1) return;
  getComp[u] = compId;
  comp.push_back(u);
  for (auto &v : ady[u]) dfsCC(v, comp);
}
// 10
// O(N)
vector<vector<int>> connectedComponents() {
  vector<vector<int>> comps;
  for (int u = 0; u < ady.size(); u++) {
    vector<int> comp;
    dfsCC(u, comp);
    if (!comp.empty()) comps.push_back(comp), compId++;
  }
  return comps;
}
// 4
void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}