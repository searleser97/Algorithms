// 5
#include "../Data Structures/Ranges/Segment Tree Lazy Propagation.cpp"
typedef int T;
vector<vector<int>> ady;
vector<int> p, heavy, depth, root, stPos, val;
SegmentTree<T> st;
// 14
T F(T a, T b) { return a + b; }

int dfs(int u) {
  int size = 1, maxSubtree = 0;
  for (int &v : ady[u]) {
    p[v] = u, depth[v] = depth[u] + 1;
    int subtree = dfs(v);
    if (subtree > maxSubtree)
      heavy[u] = v, maxSubtree = subtree;
    size += subtree;
  }
  return size;
}
// 13
void initVars(int n) {
  heavy.assign(n, -1);
  depth.assign(n, 0);
  st = SegmentTree<T>(n);
  dfs(0);
  for (int i = 0, pos = 0; i < n; i++)
    if (!i || heavy[p[i]] != i)
      for (int j = i; j; j = heavy[j]) {
        st.setValAt(val[j], pos);
        root[j] = i, stPos[j] = pos++;
      }
  st.build();
}
// 9
template <class Op>
void processPath(int u, int v, Op op) {
  for (; root[u] != root[v]; v = p[root[v]]) {
    if (depth[root[u]] > depth[root[v]]) swap(u, v);
    op(stPos[root[v]], stPos[v]);
  }
  if (depth[u] > depth[v]) swap(u, v);
  op(stPos[u] + 1, stPos[v]);
}
// 5
void modifyPath(int u, int v, T value) {
  processPath(u, v, [&value](int l, int r) {
    st.update(l, r, value);
  });
}
// 7
T query(int u, int v) {
  T ans = T();
  processPath(u, v, [&ans](int l, int r) {
    ans = F(ans, st.query(l, r));
  });
  return ans;
}
// 4
void addEdge(int u, int v, T value) {
  ady[u].push_back(v);
  val[v] = value;
}