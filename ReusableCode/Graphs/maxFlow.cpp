// uva 820 - Internet Bandwidth
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

bool hasAugmentedPath(Graph<T> &residualGraph, unordered_map<T, T> &parent, T source, T target) {
    queue<T> q;
    q.push(source);
    unordered_set<T> visited;
    visited.insert(source);
    while (!q.empty()) {
        T current = q.front(); q.pop();
        for (auto neighbor : residualGraph.nodes[current]) {
            T v = neighbor.first;
            if (!visited.count(v) && neighbor.second > 0) {
                q.push(v);
                visited.insert(v);
                parent[v] = current;
                if (v == target)
                    return true;
            }
        }
    }
    return false;
}

double maxFlow(Graph<T> &g, vector<vector<T>> &paths, T source, T target) {
    Graph<T> residualGraph(1);
    residualGraph.nodes = g.nodes;
    double max_flow = 0;
    unordered_map<T, T> parent;
    while (hasAugmentedPath(residualGraph, parent, source, target)) {
        vector<T> path;
        double flow = INF;
        T v = target;
        while (v != source) {
            T u = parent[v];
            if (flow > residualGraph.getEdgeWeight(u, v))
                flow = residualGraph.getEdgeWeight(u, v);
            path.push_back(v);
            v = u;
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        paths.push_back(path);
        max_flow += flow;
        v = target;
        while (v != source) {
            T u = parent[v];
            residualGraph.addEdge(u, v, residualGraph.getEdgeWeight(u, v) - flow);
            residualGraph.addEdge(v, u, residualGraph.getEdgeWeight(v, u) + flow);
            v = u;
        }
    }
    return max_flow;
}

int main() {
    int i = 1, n, s, t, c, u, v;
    double w;
    while (true) {
        Graph<int> g(0);
        cin >> n;
        if (!n)
            break;
        cin >> s >> t >> c;
        while (c--) {
            cin >> u >> v >> w;
            if (g.hasEdge(u, v))
                g.addEdge(u, v, g.getEdgeWeight(u, v) + w);
            else
                g.addEdge(u, v, w);
        }
        vector<vector<int>> parents;
        cout << "Network " << i << endl;
        cout << "The bandwidth is " << maxFlow(g, parents, s, t) << "." << endl;
        cout << endl;
        i++;
    }
    return 0;
}