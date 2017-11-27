#include <bits/stdc++.h>

using namespace std;
typedef int T;
class Graph {
public:
    //node -> value , neighbors
    unordered_map<T, unordered_set<T> > nodes;
    bool isDirectedGraph;

    Graph(bool isDirectedGraph) {
        this->isDirectedGraph = isDirectedGraph;
    }
    void addEdge(T v, T w) {
        this->nodes[v].insert(v);
        this->nodes[w].insert(w);
        this->nodes[v].insert(w);
        if (!isDirectedGraph)
            this->nodes[w].insert(v);
    }


private:
    void dfsTopologicalSort(unordered_set<T> neighbors, int &index, unordered_set<T> &visited, vector<T> &topologicalSortedNodes) {
        for (auto neighbor : neighbors) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                dfsTopologicalSort(this->nodes[neighbor], index, visited, topologicalSortedNodes);
                topologicalSortedNodes[index] = neighbor;
                index--;
            }
        }
    }

public:
    vector<T> topologicalSort() {
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


void printv(vector<T> v) {
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


int main() {
    while (true) {
        int n, m;
        T a, b;
        Graph *g = new Graph(true);
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
}