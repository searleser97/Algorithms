
// https://www.youtube.com/watch?v=thLQYBlz2DM
// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
#include <bits/stdc++.h>

using namespace std;
// APB = articulation points and bridges
// ap = Articulation Point
// br = bridges
// p = parent
// disc = discovery time
// low = lowTime
// ch = children

typedef pair<int, int> Edge;
int MAXN = 101, N = 7, INF = 1 << 30, Time;
vector<vector<int>> ady;
vector<int> disc, low, ap;
vector<Edge> br;

void initVars() { ady = vector<vector<int>>(MAXN, vector<int>()); }

int dfsAPB(int u, int p) {
  int ch = 0;
  low[u] = disc[u] = ++Time;
  for (int &v : ady[u]) {
    if (v == p) continue;
    if (!disc[v]) {
      ch++;
      dfsAPB(v, u);
      if (disc[u] <= low[v]) ap[u]++;
      if (disc[u] < low[v]) br.push_back({u, v});
      low[u] = min(low[u], low[v]);
    } else
      low[u] = min(low[u], disc[v]);
  }
  return ch;
}

void APB() {
  br.clear();
  ap = low = disc = vector<int>(MAXN);
  Time = 0;
  for (int u = 0; u < N; u++)
    if (!disc[u]) ap[u] = dfsAPB(u, u) > 1;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}

vector<string> split(string str, char token) {
  stringstream test(str);
  string segment;
  vector<std::string> seglist;

  while (std::getline(test, segment, token)) seglist.push_back(segment);
  return seglist;
}

string input() {
  string ans;
  cin >> ws;
  getline(cin, ans);
  return ans;
}

int main() {
  auto cmp = [](const Edge& a, const Edge& b) {
    return a.second < b.second;
  };
  int m;
  cin >> N >> m;
  initVars();
  while (m--) {
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
  }
  APB();
  int numberofaps = 0;
  for (int i = 0; i < N; i++)
    if (ap[i])
      numberofaps++;
  cout << numberofaps << endl;
  for (int i = 0; i < N; i++)
    if (ap[i])
      cout << i << " ";
  cout << endl;

  cout << br.size() << endl;
  sort(br.begin(), br.end(), cmp);
  for (auto &i : br)
    cout << i.first << " " << i.second << endl;
  return 0;
}