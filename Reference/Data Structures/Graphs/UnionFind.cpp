struct UnionFind {
  vector<int> dad, size;
  int n;
  UnionFind(int N=0) : n(N), dad(N), size(N, 1) {
    while (N--) dad[N] = N;
  }

  int root(int u) {
    if (dad[u] == u) return u;
    return dad[u] = root(dad[u]);
  }

  bool areConnected(int u, int v) {
    return root(u) == root(v);
  }

  void join(int u, int v) {
    int Ru = root(u), Rv = root(v);
    if (Ru == Rv) return;
    --n, dad[Ru] = Rv;
    size[Rv] += size[Ru];
  }

  int getSize(int u) {
    return size[root(u)];
  }

  int numberOfSets() {
    return n;
  }
};