// 6
// s = source
// returns {} if there is a negative weight cycle
// UVA 558
#include <bits/stdc++.h>
using namespace std;
typedef int T;
int INF = 1 << 30, isDirected = true;
vector<vector<int>> adj;
unordered_map<int, unordered_map<int, T>> weight;
// 4
void initVars(int N) {
  adj.assign(N, vector<int>());
  weight.clear();
}
// 7
void addEdge(int u, int v, T w) {
  adj[u].push_back(v);
  weight[u][v] = w;
  if (isDirected) return;
  adj[v].push_back(u);
  weight[v][u] = w;
}

// O(V * E)
vector<T> bellmanFordFast(int s) {
  vector<T> dist(adj.size(), INF);
  vector<int> its(adj.size()), inqueue(adj.size());
  queue<int> q;
  q.push(s), dist[s] = 0, its[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), inqueue[u] = 0;
    for (auto &v : adj[u]) {
      T d = dist[u] + weight[u][v];
      if (d < dist[v]) {
        dist[v] = d;
        if (!inqueue[v]++) q.push(v), its[v]++;
        if (its[v] == adj.size()) return {};
      }
    }
  }
  return dist;
}

#define fori(x, k) for (int i = x; i <= k; i++)

int main() {
  int tc, n;
  cin >> tc;
  fori(1, tc) {
    int m, x, y, t;
    cin >> n >> m;
    // if (i == 52) cout << n << " " << m << endl;
    initVars(n);
    while (m--) {
      cin >> x >> y >> t;
      // if (i == 52) cout << x << " " << y << " " << t << endl;
      addEdge(x, y, t);
    }
    if (bellmanFordFast(0).empty())
      cout << "possible" << endl;
    else
      cout << "not possible" << endl;
  }
  return 0;
}