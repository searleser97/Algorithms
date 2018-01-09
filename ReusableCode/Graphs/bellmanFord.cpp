// uva 558 - Wormholes
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

bool bellmanFord(Graph<T> &g, unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
    queue<T> q;
    unordered_set<T> in_queue;
    unordered_map<T, int> ocurrenceOfNodeInQueue;
    for (auto node : g.nodes) {
        distances[node.first] = INF;
        parents[node.first] = node.first;
    }
    distances[source] = 0;
    q.push(source);
    int limit = g.nodes.size() - 1;
    in_queue.insert(source);
    ocurrenceOfNodeInQueue[source] += 1;
    while (!q.empty()) {
        T u = q.front(); q.pop(); in_queue.erase(u);
        for (auto neighbor : g.nodes[u]) {
            T v = neighbor.first;
            double newDistance = distances[u] + neighbor.second;
            if (newDistance < distances[v]) {
                distances[v] = newDistance;
                parents[v] = u;
                if (!in_queue.count(v)) {
                    q.push(v);
                    ocurrenceOfNodeInQueue[v] += 1;
                    if (ocurrenceOfNodeInQueue[v] > limit)
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        unordered_map<int, double> distances;
        unordered_map<int, int> parents;
        Graph<int> g(1);
        int n, m, x, y, t;
        cin >> n >> m;
        while (m--) {
            cin >> x >> y >> t;
            g.addEdge(x, y, t);
        }
        if (!bellmanFord(g, distances, parents, 0))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}