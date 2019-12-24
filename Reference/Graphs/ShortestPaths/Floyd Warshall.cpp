// 9
// d = distance
typedef int T;
long long int inf = (1ll << 62) - 1;
vector<vector<T>> d;

void init(int n) {
  d.assign(n, vector<T>(n, inf));
  for (int i = 0; i < n; i++) d[i][i] = 0;
}
// 5
void addEdge(int u, int v, T w, bool isDirected = 0) {
  d[u][v] = w;
  if (isDirected) return;
  d[v][u] = w;
}
// 7
// O(V^3)
void floydwarshall() {
  for (int k = 0; k < d.size(); k++)
    for (int u = 0; u < d.size(); u++)
      for (int v = 0; v < d.size(); v++)
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
}