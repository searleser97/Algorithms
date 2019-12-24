// 5
// tv = top value from stack
// sccs = strongly connected components
// scc = strongly connected component
// disc = discovery time, low = low time
// s = stack, top = top index of the stack
// 5
int Time, top;
vector<vector<int>> adj, sccs;
vector<int> disc, low, s;

void init(int N) { adj.assign(N, vector<int>()); }

void addEdge(int u, int v) { adj[u].push_back(v); }
// 17
void dfsSCCS(int u) {
  if (disc[u]) return;
  low[u] = disc[u] = ++Time;
  s[++top] = u;
  for (int &v : adj[u])
    dfsSCCS(v), low[u] = min(low[u], low[v]);
  if (disc[u] == low[u]) {
    vector<int> scc;
    while (true) {
      int tv = s[top--];
      scc.push_back(tv);
      low[tv] = adj.size();
      if (tv == u) break;
    }
    sccs.push_back(scc);
  }
}
// 6
// O(N)
void SCCS() {
  s = low = disc = vector<int>(adj.size());
  Time = 0, top = -1, sccs.clear();
  for (int u = 0; u < adj.size(); u++) dfsSCCS(u);
}