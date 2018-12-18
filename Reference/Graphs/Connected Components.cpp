// comp = component
int MAXN = 26, N, compId = 0;
vector<vector<int>> ady;
vector<int> getComp;

void initVars(int N) {
  ady.assign(N, vector<int>());
  getComp.assign(N, -1);
  compId = 0;
}

void dfsCC(int u, vector<int> &comp) {
  if (getComp[u] > -1) return;
  getComp[u] = compId;
  comp.push_back(u);
  for (auto &v : ady[u]) dfsCC(v, comp);
}

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

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}