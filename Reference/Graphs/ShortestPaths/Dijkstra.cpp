typedef int Weight;
typedef pair<Weight, int> NodeDist;
int MAXN = 20001, INF = 1 << 30,
    isDirected = false;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Num>>
    weight;

void initVars(int N) {
  ady.assign(N, vector<int>());
  weight.clear();
}

vector<int> dijkstra(int s) {
  vector<int> dist(MAXN, INF);
  map<int, Num> q;
  q[s] = 0; dist[s] = 0;
  while (q.size()) {
    int u = q.begin()->first; q.erase(u);
    for (int &v : ady[u]) {
      Num w = weight[u][v];
      if (dist[u] + w < dist[v])
        q[v] = dist[v] = dist[u] + w;
    }
  }
  return dist;
}

void addEdge(int u, int v, Weight w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}