#include <bits/stdc++.h>
using namespace std;

// comp = component
int MAXN = 26, N, compId = 1;
vector<vector<int>> ady;
vector<int> getComp;

void initVars() {
  ady = vector<vector<int>>(MAXN, vector<int>());
  getComp = vector<int>(MAXN);
}

void dfsCC(int u, vector<int> &comp) {
  if (getComp[u]) return;
  getComp[u] = compId;
  comp.push_back(u);
  for (auto &v : ady[u]) dfsCC(v, comp);
}

vector<vector<int>> connectedComponents() {
  vector<vector<int>> comps;
  for (int u = 0; u < N; u++) {
    vector<int> comp;
    dfsCC(u, comp);
    compId++;
    if (!comp.empty()) comps.push_back(comp);
  }
  return comps;
}

void addEdge(int u, int v) {
  ady[u].push_back(v);
  ady[v].push_back(u);
}

string input() {
    string str;
    getline(cin, str);
    return str;
}

int main() {
    int t;
    t = stoi(input());
    input();
    while (t--) {
        initVars();
        N = input()[0] - 'A' + 1;
        while (true) {
            string edge = input();
            if (edge == "")
                break;
            addEdge(edge[0] - 'A', edge[1] - 'A');
        }
        cout << connectedComponents().size() << endl;
        if (t != 0)
            cout << endl;
    }
    return 0;
}