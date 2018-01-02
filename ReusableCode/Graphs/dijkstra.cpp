// uva 10986 - Sending email
#include <bits/stdc++.h>
#include "graphAPI.h"
#include "indexedPriorityQueue.h"
using namespace std;

typedef int T;

void dijkstra(Graph<T> &g, unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
    indexedPriorityQueue<T> ipq;
    for (auto node : g.nodes) {
        ipq.push(node.first, INF);
    }
    ipq.update(source, 0);
    distances[source] = 0;
    parents[source] = source;
    while (!ipq.empty()) {
        auto current = ipq.pop();
        distances[current.first] = current.second;
        for (auto neighbor : g.nodes[current.first]) {
            if (!ipq.containsKey(neighbor.first))
                continue;
            double newDistance = distances[current.first] + neighbor.second;
            if (ipq.getWeight(neighbor.first) > newDistance) {
                ipq.update(neighbor.first, newDistance);
                parents[neighbor.first] = current.first;
            }
        }
    }
}

int main() {
    int Te;
    cin >> Te;
    for (int l = 1; l <= Te; l++) {
        int n, m, s, t, a, b;
        double w;
        cin >> n >> m >> s >> t;
        Graph<T> g(0);
        while (m--) {
            cin >> a >> b >> w;
            g.addOrUpdateEdge(a, b, w < g.getEdgeWeight(a, b) ? w : g.getEdgeWeight(a, b));
        }
        cout << "Case #" << l << ": ";
        unordered_map<T, double> distances;
        unordered_map<T, T> parents;
        dijkstra(g, distances, parents, s);
        if (!distances.count(t)) {
            cout << "unreachable" << endl;
            continue;
        }

        if (distances[t] == INF) {
            cout << "unreachable" << endl;
            continue;
        }

        cout << distances[t] << endl;
    }
    return 0;
}