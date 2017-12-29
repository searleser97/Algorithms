#include <bits/stdc++.h>
#include "indexedPriorityQueue.cpp"

using namespace std;

double INF = 1 << 30;

template <class T> class Graph {

public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;

    // 0 -> undirected, 1 -> directed
    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }
    void addOrUpdateEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
    }

    bool hasEdge(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
    }

    double getEdgeWeight(T v, T w) {
        if (hasEdge(v, w))
            return this->nodes[v][w];
        return INF;
    }

    void dijkstra(unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
        indexedPriorityQueue<T> ipq;
        for (auto node : nodes) {
            ipq.push(node.first, INF);
        }
        ipq.update(source, 0);
        distances[source] = 0;
        parents[source] = source;
        while (!ipq.empty()) {
            auto current = ipq.pop();
            distances[current.first] = current.second;
            for (auto neighbor : nodes[current.first]) {
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
};

void printMap (unordered_map<int, double> m) {
    cout << "{ ";
    for (auto i : m)
        cout << i.first << "=" << i.second << ",";
    cout << " }" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int l = 1; l <= T; l++) {
        int n, m, s, t, a, b;
        double w;
        cin >> n >> m >> s >> t;
        Graph<int> g(0);
        while (m--) {
            cin >> a >> b >> w;
            g.addOrUpdateEdge(a, b, w < g.getEdgeWeight(a, b) ? w : g.getEdgeWeight(a, b));
        }
        cout << "Case #" << l << ": ";
        unordered_map<int, double> distances;
        unordered_map<int, int> parents;
        g.dijkstra(distances, parents, s);
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