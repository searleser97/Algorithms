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

    bool bellmanFord(unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
        queue<T> q;
        unordered_set<T> in_queue;
        unordered_map<T, int> ocurrenceOfNodeInQueue;
        for (auto node : nodes) {
            distances[node.first] = INF;
            parents[node.first] = node.first;
        }
        distances[source] = 0;
        q.push(source);
        int limit = nodes.size() - 1;
        in_queue.insert(source);
        ocurrenceOfNodeInQueue[source] += 1;
        while (!q.empty()) {
            T u = q.front(); q.pop(); in_queue.erase(u);
            for (auto neighbor : nodes[u]) {
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
        if (!g.bellmanFord(distances, parents, 0))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}