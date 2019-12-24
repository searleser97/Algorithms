#include <bits/stdc++.h>
using namespace std;
// 7
// sssp = single source shortest path
// vis = visited
typedef int T;
vector<vector<int>> ady;
vector<int> vis, toposorted;
int INF = 1 << 30;
unordered_map<int, unordered_map<int, T>> weight;
// 6
void initVars(int N) {
  ady.assign(N, vector<int>());
  vis.assign(N, 0);
  toposorted.clear();
  weight.clear();
}
// 4
void addEdge(int u, int v, int w) {
  ady[u].push_back(v);
  weight[u][v] = w;
}
// 12
// returns false if there is a cycle
// O(N)
bool toposort(int u) {
  vis[u] = 1;
  for (auto &v : ady[u])
    if (v != u && vis[v] != 2 &&
        (vis[v] || !toposort(v)))
      return false;
  vis[u] = 2;
  toposorted.push_back(u);
  return true;
}
// 13
// O(N)
vector<T> sssp(int s) {
  vector<T> dist(ady.size(), -INF);
  dist[s] = 0;
  toposort(s);
  while (toposorted.size()) {
    int u = toposorted.back();
    toposorted.pop_back();
    for (auto &v : ady[u]) {
      T w = weight[u][v], d = dist[u] + w;
      if (d > dist[v]) dist[v] = d;
    }
  }
  return dist;
}

// val = value
typedef int Val;
unordered_map<Val, int> intForVal;
unordered_map<int, Val> valForInt;
int mapId = 0;
// 5
int Map(Val val) {
  if (intForVal.count(val)) return intForVal[val];
  valForInt[mapId] = val;
  return intForVal[val] = mapId++;
}

Val IMap(int n) { return valForInt[n]; }
// 5
void initMapping() {
  mapId = 0;
  intForVal.clear();
  valForInt.clear();
}

int main() {
  int n, t = 1;
  while (cin >> n) {
    if (!n) return 0;
    initVars(n);
    initMapping();
    int s;
    cin >> s;
    while (true) {
      Val p, q;
      cin >> p >> q;
      if (!p && !q) break;
      p = Map(p), q = Map(q);
      addEdge(p, q, 1);
    }
    vector<T> v = sssp(Map(s));
    Val place = INF;
    T sp = -INF;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > sp) {
        sp = v[i];
        place = IMap(i);
      }
      if (v[i] == sp) {
        place = min(IMap(i), place);
      }
    }
    cout << "Case " << t << ": The longest path from "
         << s << " has length " << sp
         << ", finishing at " << place << "." << endl
         << endl;
    t++;
  }
  return 0;
}
