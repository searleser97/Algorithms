// 8
// N = number of nodes, Wedge = Weighted Edge
#include "../Data Structures/Graphs/UnionFind.cpp"
typedef int T;
typedef pair<int, int> Edge;
typedef pair<T, Edge> Wedge;
vector<Wedge> Wedges;
vector<Wedge> mst;
UnionFind uf(0);
// 5
void initVars(int N) {
  mst.clear();
  Wedges.clear();
  uf = UnionFind(N);
}
// 13
T kruskal() {
  T cost = 0;
  sort(Wedges.begin(), Wedges.end());
  // reverse(Wedges.begin(), Wedges.end());
  for (Wedge &wedge : Wedges) {
    int u = wedge.second.first,
        v = wedge.second.second;
    if (!uf.areConnected(u, v))
      uf.join(u, v), mst.push_back(wedge),
          cost += wedge.first;
  }
  return cost;
}
// 3
void addEdge(int u, int v, T w) {
  Wedges.push_back({w, {u, v}});
}