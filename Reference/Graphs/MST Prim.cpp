// 12
// st = spanning tree, p = parent
// vis = visited, dist = distance
typedef int T;
typedef pair<int, int> Edge;
typedef pair<T, Edge> Wedge;
typedef pair<T, int> DistNode;
long long int inf = (1ll << 62) - 1;
vector<vector<int>> adj;
unordered_map<int, unordered_map<int, T>> weight;
vector<int> p, vis;
vector<T> dist;
vector<vector<Wedge>> msts;
// 8
void init(int N) {
  adj.assign(N, vector<int>());
  p.assign(N, 0);
  vis.assign(N, 0);
  dist.assign(N, inf);
  weight.clear();
  msts.clear();
}
// 6
void addEdge(int u, int v, T w) {
  adj[u].push_back(v);
  weight[u][v] = w;
  adj[v].push_back(u);
  weight[v][u] = w;
}
// 25
// ~ O(E * log(V))
T prim(int s) {
  vector<Wedge> mst;
  vector<T> dist(adj.size(), inf);
  priority_queue<DistNode> q;
  T cost = dist[s] = 0;
  q.push({0, s});
  while (q.size()) {
    pair<int, int> aux = q.top();
    int u = aux.second;
    q.pop();
    if (dist[u] < -aux.first) continue;
    vis[u] = 1, cost += dist[u];
    mst.push_back({dist[u], {p[u], u}});
    for (int &v : adj[u]) {
      T w = weight[u][v];
      if (!vis[v] && w < dist[v])
        q.push({-(dist[v] = w), v});
    }
  }
  msts.push_back(
      vector<Wedge>(mst.begin() + 1, mst.end()));
  return cost;
}
// 8
// O(V + E * log(V))
T prim() {
  T cost = 0;
  map<int, T> q;
  for (int i = 0; i < adj.size(); i++)
    if (!vis[i]) cost += prim(i);
  return cost;
}