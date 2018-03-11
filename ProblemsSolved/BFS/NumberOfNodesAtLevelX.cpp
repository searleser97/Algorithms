#include<bits/stdc++.h>

using namespace std;

typedef unordered_map<int, unordered_set<int>> Graph;


void addEdge(int u, int v, Graph &g) {
    g[u].insert(v);
    g[v].insert(u);
}

int getNumberOfNodesAtLevelX(int x, Graph &g) {
    unordered_set<int> visited;
    unordered_map<int, int> nodeLevel;
    int numberOfNodesAtLevelX = 0;
    queue<int> q;
    q.push(1);
    visited.insert(1);
    nodeLevel[1] = 1;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if (nodeLevel[node] == x)
            numberOfNodesAtLevelX++;
        if (nodeLevel[node] > x)
            break;
        for (auto child : g[node]) {
            if (!visited.count(child)) {
                q.push(child);
                nodeLevel[child] = nodeLevel[node] + 1;
                visited.insert(child);
            }
        }
    }
    return numberOfNodesAtLevelX;
}

int main() {
    Graph g;
    int n, x;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, g);
    }
    cin >> x;
    cout << getNumberOfNodesAtLevelX(x, g) << endl;
}