#include "Flow/Max Flow Dinic.cpp"

void addEdge(int u, int v) {
  cap[u][v] = 1;
  ady[u].push_back(v);
}

int main() {
  initVars();
  int m, s = 0, t = 1;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    addEdge(u += 2, v += 2);
    addEdge(s, u);
    addEdge(v, t);
  }
  cout << dinicMaxFlow(s, t) << endl;
  return 0;
}