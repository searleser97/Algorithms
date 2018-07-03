#include <bits/stdc++.h>

using namespace std;
typedef int Weight;
int MAXN = 20001, INF = 1 << 30, isDirected = false;
vector<vector<int>> ady(MAXN, vector<int>()),
    weight(MAXN, vector<int>(MAXN, INF));

vector<Weight> bellmanFord(int s) {
  vector<Weight> dist(MAXN, INF);
  for (int i = 0; i <= N; i++) {
    for (int u = 0; u < N; u++) {
      for (auto &v : ady[u]) {
        if (dist[v] > dist[u] + weight[u][v]) {
        }
      }
    }
  }
}

void addEdge(int u, int v, Weight w) {
  ady[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  ady[v].push_back(u);
  weight[v][u] = w;
}

int main() { return 0; }