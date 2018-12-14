
// cap[a][b] = Capacity from a to b
// flow[a][b] = flow occupied from a to b
// level[a] = level in graph of node a
// Num = number
typedef int Num;
int N, MAXN = 101;
vector<int> level;
vector<vector<int>> ady;
unordered_map<int, unordered_map<int, Num>> cap, flow;

void initVars(int N) {
  ady.assign(N, vector<int>());
  cap.clear();
  flow.clear();
}

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

Num blockingFlow(int u, int t, Num currPathMaxFlow) {
  if (u == t) return currPathMaxFlow;
  for (int v : ady[u]) {
    Num capleft = cap[u][v] - flow[u][v];
    if ((level[v] == (level[u] + 1)) && (capleft > 0)) {
      Num pathMaxFlow = blockingFlow(v, t, min(currPathMaxFlow, capleft));
      if (pathMaxFlow > 0) {
        flow[u][v] += pathMaxFlow;
        flow[v][u] -= pathMaxFlow;
        return pathMaxFlow;
      }
    }
  }
  return 0;
}

// O(E * V^2)
Num dinicMaxFlow(int s, int t) {
  if (s == t) return -1;
  Num maxFlow = 0;
  while (levelGraph(s, t))
    while (Num flow = blockingFlow(s, t, 1 << 30)) maxFlow += flow;
  return maxFlow;
}

void addEdge(int u, int v, Num capacity) {
  cap[u][v] = capacity;
  ady[u].push_back(v);
}