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
    bool hasUndirectedCycle(T node, T prevNode, unordered_set<T> &visited) {
        visited.insert(node);
        for (auto neighbor : this->nodes[node]) {
            if (neighbor.first == node || neighbor.first == prevNode)
                continue;
            if (visited.count(neighbor.first))
                return true;
            if (hasUndirectedCycle(neighbor.first, node, visited))
                return true;
        }
        return false;
    }
public:
    bool hasUndirectedCycle() {
        unordered_set<T> visited;
        for (auto node : this->nodes)
            if (!visited.count(node.first)) {
                if (hasUndirectedCycle(node.first, node.first, visited))
                    return true;
            }
        return false;
    }
};

int main() {
    Graph<int> g(0);
    int n, m, u , v;
    cin >> n >> m;
    while (n--)
        g.addOrUpdateEdge(n + 1, n + 1);
    while (m--) {
        cin >> u >> v;
        g.addOrUpdateEdge(u, v);
    }
    cout << (g.hasUndirectedCycle() ? "cycle" : "no cycle") << endl;
    return 0;
}