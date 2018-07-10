typedef int Weight;
typedef pair<Weight, int> NodeDist;
int MAXN = 20001, INF = 1 << 30,
    isDirected = false;
vector<vector<int>> ady, weight;

void initVars() {
  ady = vector<vector<int>>(MAXN, vector<int>());
  weight = vector<vector<int>>(
      MAXN, vector<int>(MAXN, INF));
}

vector<Weight> dijkstra(int s) {
  vector<int> dist(MAXN, INF);
  set<NodeDist> q;
  q.insert({0, s});
  dist[s] = 0;
  while (!q.empty()) {
    NodeDist nd = *q.begin();
    q.erase(nd);
    int u = nd.second;
    for (int &v : ady[u]) {
      Weight w = weight[u][v];
      if (dist[v] > dist[u] + w) {
        if (dist[v] != INF) q.erase({dist[v], v});
        dist[v] = dist[u] + w;
        q.insert({dist[v], v});
      }
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