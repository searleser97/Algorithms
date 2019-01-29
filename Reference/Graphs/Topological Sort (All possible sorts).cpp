#include <bits/stdc++.h>
using namespace std;

vector<int> vis, indegree, path;
vector<vector<int>> ady, toposorts;
deque<int> nextNodes;

void initVars(int n) {
  ady.assign(n, vector<int>());
  vis.assign(n, 0);
  indegree = vis;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  indegree[v]++;
}

void dfs() {
  for (int i = 0; i < nextNodes.size(); i++) {
    int u = nextNodes.front(), count = 0;
    nextNodes.pop_front();
    path.push_back(u);
    for (auto &v : ady[u])
      if (!--indegree[v])
        nextNodes.push_back(v), count++;
    if (!nextNodes.size()) toposorts.push_back(path);
    dfs();
    for (auto &v : ady[u]) indegree[v]++;
    while (count--) nextNodes.pop_back();
    nextNodes.push_back(u);
    path.pop_back();
  }
}

// O(V + V!)
void allToposorts() {
  for (int u = 0; u < ady.size(); u++)
    if (!indegree[u]) nextNodes.push_back(u);
  dfs();
}

int main() {
  initVars(6);
  addEdge(5, 2);
  addEdge(5, 0);
  addEdge(4, 0);
  addEdge(4, 1);
  addEdge(2, 3);
  addEdge(3, 1);

  cout << "All Topological sorts\n";

  allToposorts();
  for (auto &path : toposorts) {
    for (auto &i : path) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}