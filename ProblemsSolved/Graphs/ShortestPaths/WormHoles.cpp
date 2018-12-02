#include <bits/stdc++.h>

using namespace std;
typedef int Weight;
int MAXN = 20001, N, INF = 1 << 30, isDirected = true;
vector<vector<int>> ady, weight;

void initVars() {
  ady = vector<vector<int>>(MAXN, vector<int>());
  weight = vector<vector<int>>(MAXN, vector<int>(MAXN, INF));
}

vector<Weight> bellmanFord(int s) {
  vector<Weight> dist(MAXN, INF);
  dist[s] = 0;
  for (int i = 1; i <= N; i++)
    for (int u = 0; u < N; u++)
      for (auto &v : ady[u]) {
        Weight w = weight[u][v];
        if (dist[u] != INF && dist[v] > dist[u] + w) {
          if (i == N) return {};
          dist[v] = dist[u] + w;
        }
      }
  return dist;
}

void addEdge(int u, int v, Weight w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    initVars();
    int m, x, y, t;
    cin >> N >> m;
    while (m--) {
      cin >> x >> y >> t;
      addEdge(x, y, t);
    }
    if (bellmanFord(0).empty())
      cout << "possible" << endl;
    else
      cout << "not possible" << endl;
  }
  return 0;
}