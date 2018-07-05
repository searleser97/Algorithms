#include <bits/stdc++.h>

using namespace std;

// tv = top value from stack
// sccs = strongly connected components
// scc = strongly connected component
// disc = discovery time
// low = low time
// s = stack
// top = top index of the stack

int MAXN = 101, N = 7, INF = 1 << 30, Time, top;
vector<vector<int>> ady, sccs;
vector<int> disc, low, s;

void initVars() { ady = vector<vector<int>>(MAXN, vector<int>()); }

void dfsSCCS(int u) {
  if (disc[u]) return;
  low[u] = disc[u] = ++Time;
  s[++top] = u;
  for (int &v : ady[u]) {
    dfsSCCS(v);
    low[u] = min(low[u], low[v]);
  }
  if (disc[u] == low[u]) {
    vector<int> scc;
    while (true) {
      int tv = s[top--];
      scc.push_back(tv);
      low[tv] = N;
      if (tv == u) break;
    }
    sccs.push_back(scc);
  }
}

void SCCS() {
  s = low = disc = vector<int>(MAXN);
  Time = 0, top = -1, sccs.clear();
  for (int u = 0; u < N; u++) dfsSCCS(u);
}

void addEdge(int u, int v) { ady[u].push_back(v); }

typedef string Key;
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
  int m, nT = 1;
  while (true) {
    cin >> N >> m;
    if (!N && !m) return 0;
    initMapping();
    initVars();
    if (nT != 1) cout << endl;
    string from, to;
    while (m--) {
      cin >> from >> to;
      addEdge(Map(from), Map(to));
    }

    SCCS();
    cout << "Calling circles for data set " << nT << ":" << endl;
    for (int i = 0; i < sccs.size(); i++) {
      cout << getKey[sccs[i][0]];
      for (int j = 1; j < sccs[i].size(); j++) cout << ", " << getKey[sccs[i][j]];
      cout << endl;
    }
    nT++;
  }
  return 0;
}