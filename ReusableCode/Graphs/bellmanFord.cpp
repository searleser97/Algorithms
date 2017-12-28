#include <bits/stdc++.h>

using namespace std;

template <class T> class Graph {

public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    double INF = 1 << 30;

    // 0 -> undirected, 1 -> directed
    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }
    void addEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        // consider the smallest edge in case of duplicates
        if (!(this->nodes.count(v) && this->nodes[v].count(w)) || (cost < this->nodes[v][w]))
            this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = this->nodes[v][w];
    }

    unordered_map<T, double> bellmanFord(T source) {
        unordered_map<T, double> distances;
        unordered_map<T, T> parents;
        queue<T> q;
        unordered_set<T> in_queue;
        for (auto node : nodes) {
            distances[node.first] = INF;
            parents[node.first] = node.first;
        }
        distances[source] = 0;
        q.push(source);
        in_queue.insert(source);
        while (!q.empty()) {
            T u = q.front(); q.pop(); in_queue.erase(u);
            for (auto neighbor : nodes[u]) {
                T v = neighbor.first;
                double newDistance = distances[u] + neighbor.second;
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    parents[v] = u;
                    if (!in_queue.count(v))
                        q.push(v);
                }
            }
        }
        return distances;
    }
};

void printMap (unordered_map<int, double> m) {
    cout << "{ ";
    for (auto i : m)
        cout << i.first << "=" << i.second << ",";
    cout << " }" << endl;
}

int main() {
    Graph<int> g(1);
    g.addEdge(0, 3, 8.0);
    g.addEdge(0, 1, 4.0);
    g.addEdge(0, 2, 5.0);
    g.addEdge(1, 2, -3.0);
    g.addEdge(2, 4, 4.0);
    g.addEdge(3, 4, 2.0);
    g.addEdge(4, 3, 1.0);
    printMap(g.bellmanFord(0));
    return 0;
}