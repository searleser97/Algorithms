// 7
// st = sparse table, p = parent
typedef pair<int, int> T;
int neutro = 0;
vector<vector<T>> st;
vector<int> first;
vector<T> tour;
vector<vector<int>> adj;

void init(int N) { adj.assign(N, vector<int>()); }
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

T F(T a, T b) { return a.first < b.first ? a : b; }
// 9
void build() {
  st.assign(log2(tour.size()),
            vector<T>(tour.size()));
  st[0] = tour;
  for (int i = 1; (1 << i) <= tour.size(); i++)
    for (int j = 0; j + (1 << i) <= tour.size(); j++)
      st[i][j] = F(st[i - 1][j],
                   st[i - 1][j + (1 << (i - 1))]);
}
// 9
void eulerTour(int u, int p, int h) {
  first[u] = tour.size();
  tour.push_back({h, u});
  for (int v : adj[u])
    if (v != p) {
      eulerTour(v, u, h + 1);
      tour.push_back({h, u});
    }
}
// 8
// O(N * lg(N))
void preprocess() {
  tour.clear();
  first.assign(adj.size(), -1);
  vector<int> roots = {0};
  for (auto &root : roots) eulerTour(root, -1, 0);
  build();
}
// 7
// O(1)
int lca(int u, int v) {
  int l = min(first[u], first[v]);
  int r = max(first[u], first[v]);
  int i = log2(r - l + 1);
  return F(st[i][l], st[i][r + 1 - (1 << i)]).second;
}