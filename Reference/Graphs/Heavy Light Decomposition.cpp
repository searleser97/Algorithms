// 6
// p = parent;
#include "../Data Structures/Ranges/Segment Tree.cpp"
typedef int T;
vector<vector<int>> ady;
vector<int> p, heavy, depth, root, stPos, vals;
SegmentTree<T> st(0);
// 7
void initVars(int n) {
  ady.assign(n, vector<int>());
  heavy.assign(n, -1);
  vals.assign(n, 0);
  p = root = stPos = depth = heavy;
  st = SegmentTree<T>(n);
}

T F(T a, T b) { return a + b; }
// 12
int dfs(int u) {
  int size = 1, maxSubtree = 0;
  for (int &v : ady[u]) {
    depth[v] = depth[u] + 1;
    int subtree = dfs(v);
    if (subtree > maxSubtree)
      heavy[u] = v, maxSubtree = subtree;
    size += subtree;
  }
  return size;
}
// 14
void initHeavyLight() {
  for (int i = 0; i < ady.size(); i++)
    if (p[i] < 0) dfs(i);
  for (int i = 0, pos = 0; i < ady.size(); i++)
    if (p[i] < 0 || heavy[p[i]] != i)
      for (int j = i; ~j; j = heavy[j]) {
        st.setValAt(vals[j], stPos[j] = pos++);
        root[j] = i;
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
  // op(stPos[u], stPos[v]); // for values on nodes
  if (u == v) return;          // for values on edges
  op(stPos[u] + 1, stPos[v]);  // for values on edges
}
// 5
void update(int u, int v, T val) {
  processPath(u, v, [&val](int l, int r) {
    st.update(l, r, val);
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
void addEdge(int u, int v, T val) {
  ady[u].push_back(v);
  p[v] = u, vals[v] = val;
}