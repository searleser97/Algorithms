// 6
// s = source
// returns {} if there is a negative weight cycle
typedef int T;
long long int inf = (1ll << 62) - 1;
vector<vector<int>> adj;
unordered_map<int, unordered_map<int, T>> weight;
// 4
void init(int N) {
  adj.assign(N, vector<int>());
  weight.clear();
}
// 7
void addEdge(int u, int v, T w, bool isDirected = 0) {
  adj[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  adj[v].push_back(u);
  weight[v][u] = w;
}
// 15
// O(V * E)
vector<T> bellmanFord(int s) {
  vector<T> dist(adj.size(), inf);
  dist[s] = 0;
  for (int i = 1; i <= adj.size(); i++)
    for (int u = 0; u < adj.size(); u++)
      for (auto &v : adj[u]) {
        T d = dist[u] + weight[u][v];
        if (dist[u] != inf && d < dist[v]) {
          if (i == adj.size()) return {};
          dist[v] = d;
        }
      }
  return dist;
}