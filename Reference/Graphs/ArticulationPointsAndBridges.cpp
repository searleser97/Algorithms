// APB = articulation points and bridges
// ap = Articulation Point
// br = bridges
// p = parent
// disc = discovery time
// low = lowTime
// ch = children

typedef pair<int, int> Edge;
int MAXN = 101, N = 7, Time;
vector<vector<int>> ady;
vector<int> disc, low, ap;
vector<Edge> br;

void initVars() { ady = vector<vector<int>>(MAXN, vector<int>()); }

int dfsAPB(int u, int p) {
  int ch = 0;
  low[u] = disc[u] = ++Time;
  for (int &v : ady[u]) {
    if (v == p) continue;
    if (!disc[v]) {
      ch++;
      dfsAPB(v, u);
      if (disc[u] <= low[v]) ap[u]++;
      if (disc[u] < low[v]) br.push_back({u, v});
      low[u] = min(low[u], low[v]);
    } else
      low[u] = min(low[u], disc[v]);
  }
  return ch;
}

void APB() {
  br.clear();
  ap = low = disc = vector<int>(MAXN);
  Time = 0;
  for (int u = 0; u < N; u++)
    if (!disc[u]) ap[u] = dfsAPB(u, u) > 1;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}