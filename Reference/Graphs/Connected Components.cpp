// comp = component
int MAXN = 26, N, compId = 1;
vector<vector<int>> ady;
vector<int> getComp;

void initVars() {
  ady = vector<vector<int>>(MAXN, vector<int>());
  getComp = vector<int>(MAXN);
}

void dfsCC(int u, vector<int> &comp) {
  if (getComp[u]) return;
  getComp[u] = compId;
  comp.push_back(u);
  for (auto &v : ady[u]) dfsCC(v, comp);
}

// O(N)
vector<vector<int>> connectedComponents() {
  vector<vector<int>> comps;
  for (int u = 0; u < N; u++) {
    vector<int> comp;
    dfsCC(u, comp);
    compId++;
    if (!comp.empty()) comps.push_back(comp);
  }
  return comps;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}