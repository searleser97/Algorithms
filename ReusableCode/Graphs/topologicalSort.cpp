// uva 10305 Ordering Tasks
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

void dfsTopologicalSort(Graph<T> &g, T current, int &index, unordered_set<T> &visited, vector<T> &topologicalSortedNodes) {
    visited.insert(current);
    for (auto neighbor : g.nodes[current])
        if (!visited.count(neighbor.first))
            dfsTopologicalSort(g, neighbor.first, index, visited, topologicalSortedNodes);
    topologicalSortedNodes[index--] = current;
}

vector<T> topologicalSort(Graph<T> &g) {
    unordered_set<T> visited;
    int index = g.nodes.size() - 1;
    vector<T> topologicalSortedNodes(g.nodes.size());
    for (auto node : g.nodes)
        if (!visited.count(node.first))
            dfsTopologicalSort(g, node.first, index, visited, topologicalSortedNodes);
    return topologicalSortedNodes;
}

void printv(vector<T> v) {
    if (v.size() == 0) {
        cout << "" << endl;
        return;
    }
    cout << "" << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << " " << v[i];
    cout << "" << endl;
}

int main() {
    while (true) {
        int n, m;
        T a, b;
        Graph<T> g(1);
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        while (n) {
            g.addOrUpdateEdge(n, n);
            n--;
        }
        while (m) {
            cin >> a >> b;
            g.addOrUpdateEdge(a, b);
            m--;
        }
        printv(topologicalSort(g));
    }
    return 0;
}