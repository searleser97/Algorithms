#include <bits/stdc++.h>
using namespace std;
    // 5
// cap[a][b] = Capacity from a to b
// flow[a][b] = flow occupied from a to b
// level[a] = level in graph of node a
// iflow = initial flow, icap = initial capacity
// pathMinCap = capacity bottleneck for a path (s->t)
// 4
typedef int T;
vector<int> level;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, T>> cap, flow;
const T INF = 1 << 30;
// 5
void initVars(int N) {
  ady.assign(N, vector<int>());
  cap.clear();
  flow.clear();
}
// 7
void addEdge(int u, int v, T icap, T iflow = 0) {
  cap[u][v] = icap;
  flow[u][v] += iflow;
  flow[v][u] -= iflow;
  ady[u].push_back(v);
  ady[v].push_back(u);
}
// 17
bool levelGraph(int s, int t) {
  level.assign(ady.size(), 0);
  level[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int &v : ady[u]) {
      if (!level[v] && flow[u][v] < cap[u][v]) {
        q.push(v);
        level[v] = level[u] + 1;
      }
    }
  }
  return level[t];
}
// 14
T blockingFlow(int u, int t, T pathMinCap) {
  if (u == t) return pathMinCap;
  for (int v : ady[u]) {
    T capLeft = cap[u][v] - flow[u][v];
    if (level[v] == (level[u] + 1) && capLeft > 0)
      if (T pathMaxFlow = blockingFlow(
          v, t, min(pathMinCap, capLeft))) {
        flow[u][v] += pathMaxFlow;
        flow[v][u] -= pathMaxFlow;
        return pathMaxFlow;
      }
  }
  return 0;
}
// 9
// O(E * V^2)
T maxFlowMinCut(int s, int t) {
  if (s == t) return INF;
  T maxFlow = 0;
  while (levelGraph(s, t))
    while (T flow = blockingFlow(s, t, INF))
      maxFlow += flow;
  return maxFlow;
}

int main() {

    return 0;
}

