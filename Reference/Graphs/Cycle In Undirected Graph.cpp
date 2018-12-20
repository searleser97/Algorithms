#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ady;
vector<bool> vis;
vector<vector<int>> cycles;
vector<int> cycle;
bool flag = false;
int rootNode = -1;

void initVars(int N) {
  ady.assign(N, vector<int>());
  cycles.clear();
  cycle.clear();
  vis.clear();
}

bool hasUndirectedCycle(int u, int prev) {
  vis[u] = true;
  for (auto &v : ady[u]) {
    if (v == u || v == prev) continue;
    if (flag) {
      hasUndirectedCycle(v, u);
      continue;
    }
    if ((vis[v] || hasUndirectedCycle(v, u))) {
      if (rootNode == -1) rootNode = v, flag = true;
      if (flag) {
        cycle.push_back(u);
        if (rootNode == u) flag = false;
      }
      return true;
    }
  }
  return false;
}

// O(N)
bool hasUndirectedCycle() {
  for (int u = 0; u < ady.size(); u++)
    if (!vis[u]) {
      cycle.clear();
      if (hasUndirectedCycle(u, -1)) cycles.push_back(cycle);
    }
  return cycles.size() > 0;
}