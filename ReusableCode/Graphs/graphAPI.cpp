#include <bits/stdc++.h>
#include "unionFind.cpp"
#include "indexedPriorityQueue.cpp"

using namespace std;
template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    UnionFind<T> uf;
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
        uf.addEdge(v, w);
    }
public:
    bool isEdgeInGraph(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
    }

private:
    void dfsCC(vector<T> &component, unordered_map<T, int> &nodeComponentIds, unordered_set<T> &visited, T actualNodeId, int &componentId) {
        visited.insert(actualNodeId);
        nodeComponentIds[actualNodeId] = componentId;
        component.push_back(actualNodeId);
        for (auto neighbor : this->nodes[actualNodeId])
            if (!visited.count(neighbor.first))
                dfsCC(component, nodeComponentIds, visited, neighbor.first, componentId);
    }

public:
    pair<vector<vector<T>>, unordered_map<T, int>> getConnectedComponents() {
        unordered_map<T, int> nodeComponentIds;
        vector<vector<T>> connectedComponents;
        unordered_set<T> visited;
        int componentId = 1;
        for (auto node : this->nodes)
            if (!visited.count(node.first)) {
                vector<T> component;
                dfsCC(component, nodeComponentIds, visited, node.first, componentId);
                connectedComponents.push_back(component);
                componentId++;
            }
        return {connectedComponents, nodeComponentIds};
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

    unordered_map<T, double> dijkstra(T source) {
        indexedPriorityQueue<T> ipq;
        unordered_map<T, double> distances;
        unordered_map<T, T> parents;
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
        return distances;
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
    int t;
    t = stoi(input());
    input();
    while (t--) {
        Graph<char> g(0);
        string highest;
        highest = input();
        for (char i = highest[0]; i >= 'A'; i--)
            g.addEdge(i, i);
        while (true) {
            string edge = input();
            if (edge == "")
                break;
            g.addEdge(edge[0], edge[1]);
        }
        pair<vector<vector<char>>, unordered_map<char, int>> connectedComponents = g.getConnectedComponents();
        cout << connectedComponents.first.size() << endl;
        if (t != 0)
            cout << endl;
    }
    return 0;
}