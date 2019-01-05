// tv = top value from stack
// sccs = strongly connected components
// scc = strongly connected component
// disc = discovery time
// low = low time
// s = stack
// top = top index of the stack
int Time, top;
vector<vector<int>> ady, sccs;
vector<int> disc, low, s;

void initVars(int N) {
  ady.assign(N, vector<int>());
}

void dfsSCCS(int u) {
  if (disc[u]) return;
  low[u] = disc[u] = ++Time;
  s[++top] = u;
  for (int &v : ady[u]) dfsSCCS(v), low[u] = min(low[u], low[v]);
  if (disc[u] == low[u]) {
    vector<int> scc;
    while (true) {
      int tv = s[top--];
      scc.push_back(tv);
      low[tv] = ady.size();
      if (tv == u) break;
    }
    sccs.push_back(scc);
  }
}
// O(N)
void SCCS() {
  s = low = disc = vector<int>(ady.size());
  Time = 0, top = -1, sccs.clear();
  for (int u = 0; u < ady.size(); u++) dfsSCCS(u);
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
}