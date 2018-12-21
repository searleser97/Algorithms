// N = number of nodes
// returns {} if there is a negative weight cycle

typedef int Num;
int MAXN = 20001, N, INF = 1 << 30, isDirected = true;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Num>> weight;

void initVars(int N) {
  ady.assign(N, vector<int>());
  weight.clear();
}

// O(V * E)
vector<Num> bellmanFord(int s) {
  vector<Num> dist(ady.size(), INF);
  dist[s] = 0;
  for (int i = 1; i <= ady.size(); i++)
    for (int u = 0; u < ady.size(); u++)
      for (auto &v : ady[u]) {
        Num w = weight[u][v];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
          if (i == ady.size()) return {};
          dist[v] = dist[u] + w;
        }
      }
  return dist;
}

void addEdge(int u, int v, Num w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}