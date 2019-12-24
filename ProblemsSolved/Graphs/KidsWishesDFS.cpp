#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ady, cycles;
vector<int> vis, cycle;
bool flag = false, isDirected = false;
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
    if (v == u || vis[v] == 2 || (!isDirected && v == prev)) continue;
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
    if (!vis[u]) cycle.clear(), hasCycle(u, -1);
  return cycles.size() > 0;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  if (!isDirected) ady[v].push_back(u);
}

typedef long long int Long;

typedef Long Key;
unordered_map<Key, int> val;
unordered_map<int, Key> getKey;
int mapId = 0;

int Map(Key key) {
  getKey[mapId] = key;
  return val.count(key) ? val[key] : val[key] = mapId++;
}

void initMapping() {
  mapId = 0;
  val.clear();
}

int main() {
  while (true) {
    Long k, w;
    cin >> k >> w;
    if (!k && !w) return 0;
    initMapping();
    initVars(2 * w);
    unordered_map<Long, Long> bucket;
    unordered_map<Long, unordered_map<Long, bool>> edges;
    Long numberOfCycles = 0LL;
    Long a, b;
    bool flag = false;
    for (Long i = 0LL; i < w; i++) {
      cin >> a >> b;
      a = Map(a);
      b = Map(b);
      if (!flag && !edges[a][b]) {
        if (a != b) {
          bucket[a]++;
          bucket[b]++;
        }
        addEdge(a, b);
        edges[a][b] = true;
        edges[b][a] = true;
        if (bucket[a] > 2LL || bucket[b] > 2LL) flag = true;
      }
    }
    if (flag)
      cout << "N" << endl;
    else if (!hasCycle() || (cycles.size() == 1 && cycles[0].size() == k))
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
}