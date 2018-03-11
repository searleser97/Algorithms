#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

bool hasDirectedCycle(Graph<T> &g, T node, T prevNode, unordered_map<T, int> &visited) {
    visited[node] = 1;
    for (auto neighbor : g.nodes[node]) {
        T v = neighbor.first;
        if (v == node || visited[v] == 2)
            continue;
        if (visited[v] == 1)
            return true;
        if (hasDirectedCycle(g, v, node, visited))
            return true;
    }
    visited[node] = 2;
    return false;
}

bool hasDirectedCycle(Graph<T> &g) {
    unordered_map<T, int> visited;
    for (auto node : g.nodes) {
        T u = node.first;
        if (!visited[u])
            if (hasDirectedCycle(g, u, u, visited))
                return true;
    }
    return false;
}

int main() {
    Graph<int> g(1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    cout << hasDirectedCycle(g) << endl;
    return 0;
}