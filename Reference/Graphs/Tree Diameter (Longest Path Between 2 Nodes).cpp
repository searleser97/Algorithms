// 3
int inf = (1 << 30) - 1;
vector<vector<int>> adj;

void init(int N) { adj.assign(N, vector<int>()); }
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
// 16
int bfs(int u) {
  vector<int> dist(adj.size(), inf);
  queue<int> q;
  q.push(u), dist[u] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int& v : adj[u])
      if (dist[v] == inf)
        q.push(v), dist[v] = dist[u] + 1;
  }
  int node, maxx = -inf;
  for (int u = 0; u < adj.size(); u++)
    if (dist[u] > maxx) maxx = dist[u], node = u;
  return node;
}
// 16
vector<int> diameter() {
  int u = bfs(0), v = bfs(u);
  vector<int> path = {v}, vis(adj.size());
  function<bool(int)> dfs = [&](int a) {
    if (a == v) return true;
    vis[a] = 1;
    for (int& b : adj[a]) {
      if (vis[b] || !dfs(b)) continue;
      path.push_back(a);
      return true;
    }
    return false;
  };
  dfs(u);
  return path;
}