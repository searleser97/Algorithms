#include <bits/stdc++.h>
#include "indexedPriorityQueue.cpp"

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
        this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
    }

    unordered_map<T, double> dijkstra(T source) {
        indexedPriorityQueue<T> ipq;
        unordered_map<T, double> distances;
        unordered_map<T, T> parents;
        for (auto node : nodes) {
            cout << node.first << endl;
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
    Graph<int> graph(1);
    graph.addEdge(1, 2, 5.0);
    graph.addEdge(2, 3, 2.0);
    graph.addEdge(1, 4, 9.0);
    graph.addEdge(1, 5, 3.0);
    graph.addEdge(5, 6, 2.0);
    graph.addEdge(6, 4, 2.0);
    graph.addEdge(3, 4, 3.0);
    printMap(graph.dijkstra(1));
    return 0;
}