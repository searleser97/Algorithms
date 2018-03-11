#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

bool hasUndirectedCycle(Graph<T> &g, T node, T prevNode, unordered_set<T> &visited) {
    visited.insert(node);
    for (auto neighbor : g.nodes[node]) {
        T v = neighbor.first;
        if (v == node || v == prevNode)
            continue;
        if (visited.count(v))
            return true;
        if (hasUndirectedCycle(g, v, node, visited))
            return true;
    }
    return false;
}

bool hasUndirectedCycle(Graph<T> &g) {
    unordered_set<T> visited;
    for (auto node : g.nodes) {
        T u = node.first;
        if (!visited.count(u))
            if (hasUndirectedCycle(g, u, u, visited))
                return true;
    }
    return false;
}

int main() {
    Graph<int> g(0);
    int n, m, u , v;
    cin >> n >> m;
    while (n--)
        g.addEdge(n + 1, n + 1);
    while (m--) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << (hasUndirectedCycle(g) ? "cycle" : "no cycle") << endl;
    return 0;
}