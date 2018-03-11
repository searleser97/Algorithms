// uva - 10004 - Bicoloring
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

bool isBipartite(Graph<T> &g) {
    unordered_map<T, bool> nodeColor;
    for (auto node : g.nodes) {
        T s = node.first;
        if (!nodeColor.count(s)) {
            nodeColor[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                T u = q.front(); q.pop();
                for (const auto &neighbor : g.nodes[u]) {
                    T v = neighbor.first;
                    if (!nodeColor.count(v)) {
                        nodeColor[v] = !nodeColor[u];
                        q.push(v);
                    }
                    if (nodeColor[v] == nodeColor[u])
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, l;
    while (true) {
        cin >> n;
        if (!n)
            return 0;
        Graph<T> g(0);
        cin >> l;
        while (l--) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }

        if (isBipartite(g))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}