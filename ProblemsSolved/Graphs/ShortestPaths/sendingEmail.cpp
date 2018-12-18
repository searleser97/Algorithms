#include <bits/stdc++.h>
using namespace std;

typedef int Weight;
typedef pair<Weight, int> DistNode;
typedef pair<int, int> Edge;
int MAXN = 20001, INF = 1 << 30, isDirected = false;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Weight>> weight;

vector<int> dijkstra(int s) {
  vector<set<DistNode>::iterator> pos(ady.size());
  vector<Weight> dist(ady.size(), INF);
  set<DistNode> q;
  q.insert({0, s}), dist[s] = 0;
  while (q.size()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    for (int &v : ady[u]) {
      Weight w = weight[u][v];
      if (dist[u] + w < dist[v]) {
        if (dist[v] != INF) q.erase(pos[v]);
        pos[v] = q.insert({dist[v] = dist[u] + w, v}).first;
      }
    }
  }
  return dist;
}

// lazy Dijkstra
// vector<int> dijkstra(int s) {
//   vector<int> dist(MAXN, INF);
//   priority_queue<DistNode, vector<DistNode>, greater<DistNode>> q;
//   q.push({0, s}), dist[s] = 0;
//   while (q.size()) {
//     DistNode top = q.top(); q.pop();
//     int u = top.second;
//     if (dist[u] < top.first) continue;
//     for (int &v : ady[u]) {
//       Weight w = weight[u][v];
//       if (dist[u] + w < dist[v]) q.push({dist[v] = dist[u] + w, v});
//     }
//   }
//   return dist;
// }

void addEdge(int u, int v, Weight w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}

void initVars(int N) {
  ady.assign(N, vector<int>());
  weight.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Te;
  cin >> Te;
  for (int l = 1; l <= Te; l++) {
    int n, m, s, t, a, b;
    double w;
    cin >> n >> m >> s >> t;
    initVars(n);
    while (m--) {
      cin >> a >> b >> w;
      if (weight[a].count(b))
        addEdge(a, b, w < weight[a][b] ? w : weight[a][b]);
      else
        addEdge(a, b, w);
    }
    vector<int> dist = dijkstra(s);

    cout << "Case #" << l << ": ";
    if (dist[t] == INF) {
      cout << "unreachable" << endl;
      continue;
    }

    cout << dist[t] << endl;
  }
  return 0;
}