// 9
// jTime = join time, t = time
struct UnionFind {
  int Time = 0;
  vector<int> dad, size, jTime;

  UnionFind(int N) : dad(N), size(N, 1), jTime(N) {
    while (N--) dad[N] = N;
  }
  // 5
  // O(lg(N))
  int root(int u, int t) {
    while (jTime[u] <= t && u != dad[u]) u = dad[u];
    return u;
  }
  // 10
  // O(1)
  void join(int u, int v, bool newTime = 1) {
    int Ru = root(u, Time), Rv = root(v, Time);
    if (newTime) Time++;
    if (Ru == Rv) return;
    if (size[Ru] > size[Rv]) swap(Ru, Rv);
    jTime[Ru] = Time;
    dad[Ru] = Rv;
    size[Rv] += size[Ru];
  }
  // 4
  // O(lg(N))
  bool areConnected(int u, int v, int t) {
    return root(u, t) == root(v, t);
  }
  // 4
  // O(lg(N))
  int getLastVersionSize(int u) {
    return size[root(u, Time)];
  }
  // 13
  // O(lg(Time) * lg(N))
  int joinTime(int u, int v) {
    int l = 0, r = Time, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (areConnected(u, v, mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};