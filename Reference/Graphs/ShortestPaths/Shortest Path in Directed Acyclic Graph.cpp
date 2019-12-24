// 12
// s = source
#include "../Topological Sort.cpp"
typedef int T;
long long int inf = (1ll << 62) - 1;
unordered_map<int, unordered_map<int, T>> weight;

void init(int N) {
  adj.assign(N, vector<int>());
  vis.assign(N, 0);
  toposorted.clear();
  weight.clear();
}
// 4
void addEdge(int u, int v, int w) {
  adj[u].push_back(v);
  weight[u][v] = w;
}
// 14
// O(N)
vector<T> dagsssp(int s) {
  vector<T> dist(adj.size(), inf);
  dist[s] = 0;
  toposort(s);
  while (toposorted.size()) {
    int u = toposorted.back();
    toposorted.pop_back();
    for (auto &v : adj[u]) {
      T d = dist[u] + weight[u][v];
      if (d < dist[v]) dist[v] = d;
    }
  }
  return dist;
}