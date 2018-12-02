#include <bits/stdc++.h>
using namespace std;

typedef int Num;
typedef pair<Num, int> NodeDist;
int MAXN = 20001, INF = 1 << 30,
    isDirected = false;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Num>>
    weight;

vector<int> dijkstra(int s) {
  vector<int> dist(MAXN, INF);
  map<int, Num> q;
  q[s] = 0;
  dist[s] = 0;
  while (q.size()) {
    int u = q.begin()->first;
    q.erase(u);
    for (int &v : ady[u]) {
      Num w = weight[u][v];
      if (dist[u] + w < dist[v])
        q[v] = dist[v] = dist[u] + w;
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
        addEdge(
            a, b,
            w < weight[a][b] ? w : weight[a][b]);
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