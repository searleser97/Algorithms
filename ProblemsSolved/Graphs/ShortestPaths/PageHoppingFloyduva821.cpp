#include <bits/stdc++.h>
using namespace std;
// d = distance
typedef int T;
int INF = (1 << 30) - 1, isDirected = true;
vector<vector<T>> d;
void initVars(int n) {
  d.assign(n, vector<T>(n, INF));
  for (int i = 0; i < n; i++) d[i][i] = 0;
}

void addEdge(int u, int v, T w) {
  d[u][v] = w;
  if (isDirected) return;
  d[v][u] = w;
}
void floydwarshall() {
  for (int k = 0; k < d.size(); k++)
    for (int u = 0; u < d.size(); u++)
      for (int v = 0; v < d.size(); v++)
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int u = 0, v = 0, tc = 1;
  while (true) {
    cin >> u >> v;
    if (!u && !v) break;
    initVars(105);
    int pairsCount = 0;
    while (true) {
      addEdge(--u, --v, 1);
      cin >> u >> v;
      if (!u && !v) break;
    }
    floydwarshall();
    double ans = 0;
    for (int i = 0; i < 105; i++)
      for (int j = 0; j < 105; j++)
        if (d[i][j] < INF) {
          ans += d[i][j];
          if (i != j) pairsCount++;
        }
    ans /= pairsCount;
    cout << fixed << setprecision(3);
    cout << "Case " << tc++
         << ": average length between pages = " << ans
         << " clicks" << endl;
  }
  return 0;
}