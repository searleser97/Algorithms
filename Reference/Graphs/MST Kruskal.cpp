// N = number of nodes
#include "../Data Structures/Graphs/UnionFind.cpp"
typedef int Weight;
typedef pair<int, int> Edge;
typedef pair<Weight, Edge> Wedge;
vector<Wedge> Wedges;  // gets filled from input;
vector<Wedge> mst;
UnionFind uf(0);

void initVars(int N) {
  mst.clear();
  Wedges.clear();
  uf = UnionFind(N);
}

Weight kruskal() {
  Weight cost = 0;
  sort(Wedges.begin(), Wedges.end());
  // reverse(Wedges.begin(), Wedges.end());
  for (Wedge &wedge : Wedges) {
    int u = wedge.second.first, v = wedge.second.second;
    if (!uf.areConnected(u, v)) uf.join(u, v), mst.push_back(wedge), cost += wedge.first;
  }
  return cost;
}

void addEdge(int u, int v, Weight w) {
  Wedges.push_back({w, {u, v}});
}