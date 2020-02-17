// 6
// s = source, its = iterations of node u
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
// 19
// O(V * E)
vector<T> bellmanFordFast(int s) {
  vector<long long int> dist(adj.size(), inf);
  vector<int> its(adj.size()), inqueue(adj.size());
  queue<int> q;
  q.push(s), dist[s] = 0, its[s] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop(), inqueue[u] = 0;
    for (auto &v : adj[u]) {
      T d = dist[u] + weight[u][v];
      if (d < dist[v]) {
        dist[v] = d;
        if (!inqueue[v]++) q.push(v), its[v]++;
        if (its[v] == adj.size()) return {};
      }
    }
  }
  return dist;
}