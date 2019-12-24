#include <bits/stdc++.h>
using namespace std;
template <class T>
struct SegmentTree {
  T neutro = 0;
  int N;
  vector<T> st;
  // 8
  SegmentTree(int n) : st(2 * n, neutro), N(n) {}

  T F(T a, T b) { return max(a, b); }
  // 5
  // O(2N)
  void build() {
    for (int i = N - 1; i > 0; i--)
      st[i] = F(st[i << 1], st[i << 1 | 1]);
  }
  // 5
  // O(lg(2N))
  void update(int i, T val) {
    for (st[i += N] = val; i > 1; i >>= 1)
      st[i >> 1] = F(st[i], st[i ^ 1]);
  }
  // 5
  // O(3N), [l, r]
  void update(int l, int r, T val) {
    if (l == r)
      update(l, val);
    else {
      for (l += N, r += N; l <= r; l++) st[l] = val;
      build();
    }
  }
  // 9
  // O(lg(2N)), [l, r]
  T query(int l, int r) {
    T ans = neutro;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = F(ans, st[l++]);
      if (~r & 1) ans = F(ans, st[r--]);
    }
    return ans;
  }
  // 2
  void setValAt(T val, int i) { st[i + N] = val; }
};
// p = parent;
// 5
// #include "../Data Structures/Ranges/Segment
// Tree.cpp"
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

T F(T a, T b) { return max(a, b); }
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

// val = value
typedef int Val;
unordered_map<Val, int> intForVal;
unordered_map<int, Val> valForInt;
int mapId;
// 4
int Map(Val val) {
  valForInt[mapId] = val;
  return intForVal.count(val)
             ? intForVal[val]
             : intForVal[val] = mapId++;
}
// 3
Val IMap(int val) { return valForInt[val]; }
// 5
void initMapping() {
  mapId = 0;
  intForVal.clear();
  valForInt.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    initVars(n);
    initMapping();
    vector<pair<Val, Val>> edges;
    for (int i = 0; i < n - 1; i++) {
      Val a, b;
      T c;
      cin >> a >> b >> c;
      a = Map(a), b = Map(b);
      addEdge(a, b, c);
      edges.push_back({a, b});
    }
    initHeavyLight();
    while (true) {
      string op;
      cin >> op;
      if (op[0] == 'Q') {
        int a, b;
        cin >> a >> b;
        cout << query(Map(a), Map(b)) << endl;
      }
      if (op[0] == 'C') {
        int i, ti;
        cin >> i >> ti;
        i--;
        update(edges[i].first, edges[i].second, ti);
      }
      if (op[0] == 'D') break;
    }
  }
  return 0;
}