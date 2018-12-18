// st = spanning tree, p = parent
// vis = visited, dist = distance
typedef int Weight;
typedef pair<int, int> Edge;
typedef pair<Weight, Edge> Wedge;
typedef pair<Weight, int> DistNode;
int MAXN = 20001, INF = 1 << 30;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Weight>> weight;
vector<int> p, vis;
vector<Weight> dist;
vector<vector<Wedge>> msts;

void initVars(int N) {
  ady.assign(N, vector<int>());
  p.assign(N, 0);
  vis.assign(N, 0);
  dist.assign(N, INF);
  weight.clear();
  msts.clear();
}

Weight prim(int s) {
  vector<Wedge> mst;
  vector<set<Edge>::iterator> pos(ady.size());
  vector<Weight> dist(ady.size(), INF);
  set<Edge> q;
  Weight cost = dist[s] = 0;
  q.insert({0, s});
  while (q.size()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    vis[u] = 1, cost += dist[u];
    mst.push_back({dist[u], {p[u], u}});
    for (int &v : ady[u]) {
      Weight w = weight[u][v];
      if (!vis[v] && w < dist[v]) {
        if (dist[v] != INF) q.erase(pos[v]);
        pos[v] = q.insert({dist[v] = w, v}).first;
      }
    }
  }
  msts.push_back(vector<Wedge>(mst.begin() + 1, mst.end()));
  return cost;
}

Weight primLazy(int s) {
  vector<Wedge> mst;
  vector<set<Edge>::iterator> pos(ady.size());
  vector<Weight> dist(ady.size(), INF);
  priority_queue<DistNode, vector<DistNode>, greater<DistNode>> q;
  Weight cost = dist[s] = 0;
  q.push({0, s});
  while (q.size()) {
    pair<int, int> aux = q.top();
    int u = aux.second;
    q.pop();
    if (dist[u] < aux.first) continue;
    vis[u] = 1, cost += dist[u];
    mst.push_back({dist[u], {p[u], u}});
    for (int &v : ady[u]) {
      Weight w = weight[u][v];
      if (!vis[v] && w < dist[v]) q.push({dist[v] = w, v});
    }
  }
  msts.push_back(vector<Wedge>(mst.begin() + 1, mst.end()));
  return cost;
}

// O(V + E * log(V))
Weight prim() {
  Weight cost = 0;
  map<int, Weight> q;
  for (int i = 0; i < ady.size(); i++)
    if (!vis[i]) cost += prim(i);
  return cost;
}

void addEdge(int u, int v, Weight w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  ady[v].push_back(u);
  weight[v][u] = w;
}