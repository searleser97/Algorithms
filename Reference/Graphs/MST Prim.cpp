// st = spanning tree, p = parent
// vis = visited, dist = distance
typedef int Num;
typedef pair<int, int> Edge;
typedef pair<Num, Edge> Wedge;
typedef pair<Num, int> DistNode;
int MAXN = 20001, INF = 1 << 30;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Num>> weight;
vector<int> p, vis;
vector<Num> dist;
vector<vector<Wedge>> msts;

void initVars(int N) {
  ady.assign(N, vector<int>());
  p.assign(N, 0);
  vis.assign(N, 0);
  dist.assign(N, INF);
  weight.clear();
  msts.clear();
}

Num prim(int s) {
  vector<Wedge> mst;
  vector<set<Edge>::iterator> pos(ady.size());
  vector<Num> dist(ady.size(), INF);
  set<Edge> q;
  Num cost = dist[s] = 0;
  q.insert({0, s});
  while (q.size()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    vis[u] = 1, cost += dist[u];
    mst.push_back({dist[u], {p[u], u}});
    for (int &v : ady[u]) {
      Num w = weight[u][v];
      if (!vis[v] && w < dist[v]) {
        if (dist[v] != INF) q.erase(pos[v]);
        pos[v] = q.insert({dist[v] = w, v}).first;
      }
    }
  }
  msts.push_back(vector<Wedge>(mst.begin() + 1, mst.end()));
  return cost;
}

Num primLazy(int s) {
  vector<Wedge> mst;
  vector<set<Edge>::iterator> pos(ady.size());
  vector<Num> dist(ady.size(), INF);
  priority_queue<DistNode, vector<DistNode>, greater<DistNode>> q;
  Num cost = dist[s] = 0;
  q.push({0, s});
  while (q.size()) {
    pair<int, int> aux = q.top();
    int u = aux.second;
    q.pop();
    if (dist[u] < aux.first) continue;
    vis[u] = 1, cost += dist[u];
    mst.push_back({dist[u], {p[u], u}});
    for (int &v : ady[u]) {
      Num w = weight[u][v];
      if (!vis[v] && w < dist[v]) q.push({dist[v] = w, v});
    }
  }
  msts.push_back(vector<Wedge>(mst.begin() + 1, mst.end()));
  return cost;
}

// O(V + E * log(V))
Num prim() {
  Num cost = 0;
  map<int, Num> q;
  for (int i = 0; i < ady.size(); i++)
    if (!vis[i]) cost += prim(i);
  return cost;
}

void addEdge(int u, int v, Num w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  ady[v].push_back(u);
  weight[v][u] = w;
}