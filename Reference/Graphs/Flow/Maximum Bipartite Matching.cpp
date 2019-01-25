// mbm = maximum bipartite matching
#include "Max Flow Dinic.cpp"
// 4
void addEdgeMBM(int u, int v) {
  addEdge(u += 2, v += 2, 1);
  addEdge(0, u, 1);
  addEdge(v, 1, 1);
}
// 2
// O(E * V^2)
T mbm() { return dinicMaxFlow(0, 1); }