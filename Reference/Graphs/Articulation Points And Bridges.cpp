// 5
// APB = articulation points and bridges
// ap = Articulation Point
// br = bridges, p = parent
// disc = discovery time
// low = lowTime, ch = children
// 5
typedef pair<int, int> Edge;
int Time;
vector<vector<int>> ady;
vector<int> disc, low, ap;
vector<Edge> br;
// 1
void initVars(int N) { ady.assign(N, vector<int>()); }
// 15
int dfsAPB(int u, int p) {
  int ch = 0;
  low[u] = disc[u] = ++Time;
  for (int &v : ady[u]) {
    if (v == p) continue;
    if (!disc[v]) {
      ch++, dfsAPB(v, u);
      if (disc[u] <= low[v]) ap[u]++;
      if (disc[u] < low[v]) br.push_back({u, v});
      low[u] = min(low[u], low[v]);
    } else
      low[u] = min(low[u], disc[v]);
  }
  return ch;
}
// 8
// O(N)
void APB() {
  br.clear();
  ap = low = disc = vector<int>(ady.size());
  Time = 0;
  for (int u = 0; u < ady.size(); u++)
    if (!disc[u]) ap[u] = dfsAPB(u, u) > 1;
}
// 4
void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}