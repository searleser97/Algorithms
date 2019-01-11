struct UnionFind {
  vector<int> dad, size;
  int n;
  // 3
  UnionFind(int N = 0) : n(N), dad(N), size(N, 1) {
    while (N--) dad[N] = N;
  }
  // 4
  int root(int u) {
    if (dad[u] == u) return u;
    return dad[u] = root(dad[u]);
  }
  // 3
  bool areConnected(int u, int v) {
    return root(u) == root(v);
  }
  // 6
  void join(int u, int v) {
    int Ru = root(u), Rv = root(v);
    if (Ru == Rv) return;
    --n, dad[Ru] = Rv;
    size[Rv] += size[Ru];
  }
  // 3
  int getSize(int u) {
    return size[root(u)];
  }
  // 4
  int numberOfSets() {
    return n;
  }
};