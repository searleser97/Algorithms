#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ady, cycles;
vector<int> vis, cycle;
bool flag = false, isUndirected = true;
int root = -1;

void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  cycles.clear();
  root = -1, flag = false;
}

bool hasCycle(int u, int prev) {
  vis[u] = 1;
  for (auto &v : ady[u]) {
    if (v == u || vis[v] == 2 || (isUndirected && v == prev)) continue;
    if (flag) {
      if (!vis[v]) hasCycle(v, u);
      continue;
    }
    if (vis[v] || hasCycle(v, u)) {
      if (root == -1) root = v, flag = true;
      cycle.push_back(u);
      if (root == u) flag = false, root = -1, cycles.push_back(cycle), cycle.clear();
    }
  }
  vis[u] = 2;
  return flag;
}

// O(N)
bool hasCycle() {
  for (int u = 0; u < ady.size(); u++)
    if (!vis[u]) {
      cycle.clear();
      if (hasCycle(u, -1)) cycles.push_back(cycle);
    }
  return cycles.size() > 0;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}

int main() {
  initVars(7);
  addEdge(0, 4);
  addEdge(4, 1);
  addEdge(4, 2);
  addEdge(1, 2);
  addEdge(1, 3);
  addEdge(3, 2);
  addEdge(4, 5);
  addEdge(4, 6);
  addEdge(6, 5);
  if (hasCycle()) {
    for (auto cycle : cycles) {
      for (auto u : cycle) {
        cout << u << " ";
      }
      cout << endl;
    }
  }
  return 0;
}