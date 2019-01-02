// st = sparse table
typedef pair<int, int> T;
int neutro = 0;
vector<vector<T>> st;

vector<int> first;
vector<T> tour;
vector<vector<int>> ady;

void initVars(int N) {
  ady.assign(N, vector<int>());
}

T F(T a, T b) {
  return a.first < b.first ? a : b;
}

void build() {
  st.assign(ceil(log2(tour.size())), vector<T>(tour.size()));
  st[0] = tour;
  for (int i = 1; (1 << i) <= tour.size(); i++)
    for (int j = 0; j + (1 << i) <= tour.size(); j++) st[i][j] = F(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

void eulerTour(int u, int p, int h) {
  first[u] = tour.size();
  tour.push_back({h, u});
  for (int v : ady[u])
    if (v != p) {
      eulerTour(v, u, h + 1);
      tour.push_back({h, u});
    }
}

void preprocess() {
  tour.clear();
  first.assign(ady.size(), -1);
  eulerTour(0, 0, 0);
  build();
}

int lca(int u, int v) {
  int l = min(first[u], first[v]);
  int r = max(first[u], first[v]);
  int i = log2(r - l + 1);
  return F(st[i][l], st[i][r + 1 - (1 << i)]).second;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}