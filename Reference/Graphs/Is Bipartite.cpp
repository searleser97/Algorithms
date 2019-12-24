// 3
vector<vector<int>> adj;

void init(int N) { adj.assign(N, vector<int>()); }
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
// 20
// O(N)
bool isBipartite() {
  vector<int> color(adj.size(), -1);
  for (int s = 0; s < adj.size(); s++) {
    if (color[s] > -1) continue;
    color[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int &v : adj[u]) {
        if (color[v] < 0)
          q.push(v), color[v] = !color[u];
        if (color[v] == color[u]) return false;
      }
    }
  }
  return true;
}