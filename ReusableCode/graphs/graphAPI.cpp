#include <bits/stdc++.h>
#include "unionFind.h"

using namespace std;
template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    UnionFind<T> uf;

    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }
    void addEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = cost;
        this->nodes[w][w] = cost;
        this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
        uf.addEdge(v, w);
    }
public:
    bool isEdgeInGraph(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
    }

private:
    void dfsConnectedComponents(unordered_map<T, double> &vertexesInComponent, unordered_set<T> &visited, vector<T> &connectedComponents) {
        for (auto vertex : vertexesInComponent) {
            if (!visited.count(vertex.first)) {
                connectedComponents.push_back(vertex.first);
                visited.insert(vertex.first);
                dfsConnectedComponents(this->nodes[vertex.first], visited, connectedComponents);
            }
        }
    }

public:
    vector< vector<T> > getConnectedComponents() {
        unordered_set<T> visited;
        vector< vector<T> > connectedComponents;
        if (this->isDirectedGraph)
            return connectedComponents;
        for (auto edge : this->nodes) {
            if (!visited.count(edge.first)) {
                vector<T> vertexesInComponent;
                vertexesInComponent.push_back(edge.first);
                visited.insert(edge.first);
                dfsConnectedComponents(edge.second, visited, vertexesInComponent);
                connectedComponents.push_back(vertexesInComponent);
            }
        }
        return connectedComponents;
    }
public:
    bool areVertexesConnected(T v, T w) {
        return this->uf.areVertexesConnected(v, w);
    }

private:
    void dfsTopologicalSort(unordered_map<T, double> neighbors, int &index, unordered_set<T> &visited, vector<T> &topologicalSortedNodes) {
        for (auto neighbor : neighbors) {
            if (!visited.count(neighbor.first)) {
                visited.insert(neighbor.first);
                dfsTopologicalSort(this->nodes[neighbor.first], index, visited, topologicalSortedNodes);
                topologicalSortedNodes[index] = neighbor.first;
                index--;
            }
        }
    }

public:
    vector<T> topologicalSort() {
        if (!this->isDirectedGraph) {
            vector<T> trash;
            return trash;
        }
        unordered_set<T> visited;
        vector<T> topologicalSortedNodes(this->nodes.size());
        int index = this->nodes.size() - 1;
        for (auto edge : this->nodes) {
            if (!visited.count(edge.first)) {
                visited.insert(edge.first);
                dfsTopologicalSort(edge.second, index, visited, topologicalSortedNodes);
                topologicalSortedNodes[index] = edge.first;
                index--;
            }
        }
        return topologicalSortedNodes;
    }

};


void printv(vector<int> v) {
    if (v.size() == 0) {
        cout << "" << endl;
        return;
    }
    cout << "" << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "" << endl;
}


/*int main() {
    while (true) {
        int n, m;
        int a, b;
        auto *g = new Graph<int>(true);
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        while (n) {
            g->addEdge(n, n);
            n--;
        }
        while (m) {
            cin >> a >> b;
            g->addEdge(a, b);
            m--;
        }
        printv(g->topologicalSort());
        delete g;
    }



    return 0;
}*/
int main() {
    Graph<int> g(0);
    int a, b;
    int i;
    cin >> i;
    while (i--) {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    for (auto v : g.getConnectedComponents()) {
        printv(v);
    }
    cin >> i;
    while (i--) {
        cin >> a >> b;
        cout << g.areVertexesConnected(a, b) << '\n';
    }
    return 0;
}