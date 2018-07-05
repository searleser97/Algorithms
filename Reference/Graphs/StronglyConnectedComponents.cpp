// tv = top value from stack
// sccs = strongly connected components
// scc = strongly connected component
// disc = discovery time
// low = low time
// s = stack
// top = top index of the stack

int MAXN = 101, N = 7, Time, top;
vector<vector<int>> ady, sccs;
vector<int> disc, low, s;

void initVars() { ady = vector<vector<int>>(MAXN, vector<int>()); }

void dfsSCCS(int u) {
  if (disc[u]) return;
  low[u] = disc[u] = ++Time;
  s[++top] = u;
  for (int &v : ady[u]) {
    dfsSCCS(v);
    low[u] = min(low[u], low[v]);
  }
  if (disc[u] == low[u]) {
    vector<int> scc;
    while (true) {
      int tv = s[top--];
      scc.push_back(tv);
      low[tv] = N;
      if (tv == u) break;
    }
    sccs.push_back(scc);
  }
}

void SCCS() {
  s = low = disc = vector<int>(MAXN);
  Time = 0, top = -1, sccs.clear();
  for (int u = 0; u < N; u++) dfsSCCS(u);
}

void addEdge(int u, int v) { ady[u].push_back(v); }