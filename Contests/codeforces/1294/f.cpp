#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forr(_, x, n) for (int _ = x; ~_; _--)
#define fos(_, x, n, s) for (int _ = x; _ < n; _ += s)
#define forn(_, x, n) fos(_, x, n, 1)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
// typedef __int128_t lli;
typedef long long int li;
typedef long double ld;
// 3
int inf = (1 << 30) - 1;
vector<vector<int>> adj;

void init(int N) { adj.assign(N, vector<int>()); }
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
// 16
int bfs(int u) {
  vector<int> dist(adj.size(), inf);
  queue<int> q;
  q.push(u), dist[u] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int& v : adj[u])
      if (dist[v] == inf)
        q.push(v), dist[v] = dist[u] + 1;
  }
  int node, maxx = -inf;
  for (int u = 0; u < adj.size(); u++)
    if (dist[u] > maxx) maxx = dist[u], node = u;
  return node;
}
// 16
vector<int> diameter() {
  int u = bfs(0), v = bfs(u);
  vector<int> path = {v}, vis(adj.size());
  function<bool(int)> dfs = [&](int a) {
    if (a == v) return true;
    vis[a] = 1;
    for (int& b : adj[a]) {
      if (vis[b] || !dfs(b)) continue;
      path.push_back(a);
      return true;
    }
    return false;
  };
  dfs(u);
  return path;
}

// 12
void _main(int tc) {
  int n;
  cin >> n;
  init(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    addEdge(u, v);
  }
  auto d = diameter();
  queue<int> q;
  vector<int> dist(adj.size(), inf);
  rep(i, d.size()) q.push(d[i]), dist[d[i]] = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int& v : adj[u]) {
      if (dist[v] == inf) {
        q.push(v), dist[v] = dist[u] + 1;
      }
    }
  }
  int node, maxx = -inf;
  for (int u = 0; u < adj.size(); u++)
    if (dist[u] > maxx) maxx = dist[u], node = u;
  cout << d.size() - 1 + maxx << endl;
  if (d[0] == node) node = d[1];
  cout << d[0] + 1 << " " << d.back() + 1 << " " << node + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0); return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
} 
