#include<bits/stdc++.h>
using namespace std;

template <class T> class Graph {
    public:
        unordered_map<T, unordered_map<T, double> > nodes;
        bool isDirectedGraph;
        Graph(bool idDirectedGraph = false) {
            this->isDirectedGraph = isDirectedGraph;
        }

        bool hasNode(T node) {
            return this->nodes.count(node);
        }

        void addNode(T newNode) {
            if (!hasNode(newNode))
                this->nodes[newNode];
        }

        void addEdge(T v, T w, double cost = 0) {
            addNode(v);
            addNode(w);
            this->nodes[v][w] = cost;
            if (isDirectedGraph)
                return;
            this->nodes[w][v] = cost;
        }
};

typedef int T;

void dfsTopologicalSort(Graph<T> &g, T current, int &index, unordered_set<T> &visited, vector<T> &topologicalSortedNodes) {
    visited.insert(current);
    for (auto neighbor : g.nodes[current])
        if (!visited.count(neighbor.first))
            dfsTopologicalSort(g, neighbor.first, index, visited, topologicalSortedNodes);
    topologicalSortedNodes[index--] = current;
}

vector<T> topologicalSort(Graph<T> &g) {
    unordered_set<T> visited;
    int index = g.nodes.size() - 1;
    vector<T> topologicalSortedNodes(g.nodes.size());
    vector<int> keys;
    for (auto node : g.nodes)
        keys.push_back(node.first);
    sort(keys.begin(), keys.end());
    for (int i = 0; i < keys.size(); i++)
        if (!visited.count(keys[i]))
            dfsTopologicalSort(g, keys[i], index, visited, topologicalSortedNodes);
    return topologicalSortedNodes;
}

int main() {
    Graph<int> g(1);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g.addNode(i);
    while(m--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    vector<int> topoSorted = topologicalSort(g);
    for (int i = 0; i < topoSorted.size(); i++)
        cout << topoSorted[i] << " ";
    cout << endl;
}