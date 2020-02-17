// 5
// s = source
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
// 17
// O(E)
vector<T> bfs(int s) {
  vector<long long int> dist(adj.size(), inf);
  dist[s] = 0;
  deque<int> q;
  q.push_front(s);
  while (q.size()) {
    int u = q.front(); q.pop_front();
    for (auto& v : adj[u]) {
      T d = dist[u] + weight[u][v];
      if (d < dist[v])
        weight[u][v] ? q.push_back(v)
                     : q.push_front(v);
    }
  }
  return dist;
}