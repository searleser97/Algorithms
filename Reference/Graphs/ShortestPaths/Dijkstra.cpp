// 5
typedef int T;
typedef pair<T, int> DistNode;
int INF = 1 << 30, isDirected = false;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, T>> weight;
// 4
void initVars(int N) {
  ady.assign(N, vector<int>());
  weight.clear();
}
// 20
// O(E * lg(V))
vector<T> dijkstra(int s) {
  vector<set<DistNode>::iterator> pos(ady.size());
  vector<T> dist(ady.size(), INF);
  set<DistNode> q;
  q.insert({0, s}), dist[s] = 0;
  while (q.size()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    for (int &v : ady[u]) {
      T w = weight[u][v];
      if (dist[u] + w < dist[v]) {
        if (dist[v] != INF) q.erase(pos[v]);
        pos[v] = q.insert({dist[v] = dist[u] + w, v})
                     .first;
      }
    }
  }
  return dist;
}
// 17
vector<T> dijkstraLazy(int s) {
  vector<T> dist(ady.size(), INF);
  priority_queue<DistNode, vector<DistNode>,
                 greater<DistNode>>
      q;
  q.push({0, s}), dist[s] = 0;
  while (q.size()) {
    DistNode top = q.top();
    q.pop();
    int u = top.second;
    if (dist[u] < top.first) continue;
    for (int &v : ady[u]) {
      T w = weight[u][v];
      if (dist[u] + w < dist[v])
        q.push({dist[v] = dist[u] + w, v});
    }
  }
  return dist;
}
// 7
void addEdge(int u, int v, T w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}