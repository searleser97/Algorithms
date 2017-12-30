#include<bits/stdc++.h>

using namespace std;

template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;

    // 0 -> undirected, 1 -> directed
    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }

    unordered_map<T, unordered_map<T, double> > getNodes() {
        return this->nodes;
    }

    void addOrUpdateEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
    }

private:
    bool hasDirectedCycle(T node, T prevNode, unordered_map<T, int> &visited) {
        visited[node] = 1;
        for (auto neighbor : this->nodes[node]) {
            T v = neighbor.first;
            if (v == node || v == prevNode || visited[v] == 2)
                continue;
            if (visited[v] == 1)
                return true;
            if (hasDirectedCycle(v, node, visited))
                return true;
        }
        visited[node] = 2;
        return false;
    }
public:
    bool hasDirectedCycle() {
        unordered_map<T, int> visited;
        for (auto node : this->nodes)
            if (!visited[node.first])
                if (hasDirectedCycle(node.first, node.first, visited))
                    return true;
        return false;
    }
};

int main() {
    Graph<int> g(1);
    g.addOrUpdateEdge(1, 2);
    g.addOrUpdateEdge(1, 3);
    g.addOrUpdateEdge(2, 3);
    g.addOrUpdateEdge(4, 1);
    g.addOrUpdateEdge(4, 5);
    g.addOrUpdateEdge(5, 6);
    g.addOrUpdateEdge(6, 4);
    cout << g.hasDirectedCycle() << endl;
    return 0;
}