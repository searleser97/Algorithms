// 3
// cap[a][b] = Capacity from a to b
// flow[a][b] = flow occupied from a to b
// level[a] = level in graph of node a
// 4
typedef int T;
vector<int> level;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, T>> cap, flow;
// 5
void initVars(int N) {
  ady.assign(N, vector<int>());
  cap.clear();
  flow.clear();
}
// 4
void addEdge(int u, int v, T capacity) {
  cap[u][v] = capacity;
  ady[u].push_back(v);
}
// 17
bool levelGraph(int s, int t) {
  level = vector<int>(ady.size());
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
// 17
T blockingFlow(int u, int t, T currPathMaxFlow) {
  if (u == t) return currPathMaxFlow;
  for (int v : ady[u]) {
    T capleft = cap[u][v] - flow[u][v];
    if ((level[v] == (level[u] + 1)) &&
        (capleft > 0)) {
      T pathMaxFlow = blockingFlow(
          v, t, min(currPathMaxFlow, capleft));
      if (pathMaxFlow > 0) {
        flow[u][v] += pathMaxFlow;
        flow[v][u] -= pathMaxFlow;
        return pathMaxFlow;
      }
    }
  }
  return 0;
}
// 9
// O(E * V^2)
T dinicMaxFlow(int s, int t) {
  if (s == t) return -1;
  T maxFlow = 0;
  while (levelGraph(s, t))
    while (T flow = blockingFlow(s, t, 1 << 30))
      maxFlow += flow;
  return maxFlow;
}