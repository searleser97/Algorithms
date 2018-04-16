// uva 10305 Ordering Tasks
#include <bits/stdc++.h>
using namespace std;

double INF = 1 << 30;

template <class T> class Edge {
public:
    T v, w;
    double weight;
    Edge(T v, T w, double weight = 0) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
};

template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    vector<Edge<T>> edges;

    // 0 -> undirected, 1 -> directed
    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }

    unordered_map<T, unordered_map<T, double> > getNodes() {
        return this->nodes;
    }

    bool hasNode(T node) {
        return this->nodes.count(node);
    }

    void addNode(T newNode) {
        if (!hasNode(newNode))
            this->nodes[newNode];
    }

    T nextNode() {
        return this->nodes.begin()->first;
    }

    vector<Edge<T>> getEdges() {
        return this->edges;
    }

    bool hasEdge(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
    }

    double getEdgeWeight(T v, T w) {
        if (hasEdge(v, w))
            return this->nodes[v][w];
        return INF;
    }

    void addEdge(T v, T w, double cost = 0) {
        addNode(v);
        addNode(w);
        this->nodes[v][w] = cost;
        this->edges.push_back(Edge<T>(v, w, cost));
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
        this->edges.push_back(Edge<T>(w, v, cost));
    }

    void printEdges() {
        for (auto edge : this->edges)
            cout << edge.v << " " << edge.w << " " << edge.weight << endl;
    }
};

typedef int T;

bool hasDirectedCycle(Graph<T> &g, T node, T prevNode, unordered_map<T, int> &visited) {
    visited[node] = 1;
    for (auto neighbor : g.nodes[node]) {
        T v = neighbor.first;
        if (v == node || visited[v] == 2)
            continue;
        if (visited[v] == 1)
            return true;
        if (hasDirectedCycle(g, v, node, visited))
            return true;
    }
    visited[node] = 2;
    return false;
}

bool hasDirectedCycle(Graph<T> &g) {
    unordered_map<T, int> visited;
    for (auto node : g.nodes) {
        T u = node.first;
        if (!visited[u])
            if (hasDirectedCycle(g, u, u, visited))
                return true;
    }
    return false;
}

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
    for (auto node : g.nodes)
        if (!visited.count(node.first))
            dfsTopologicalSort(g, node.first, index, visited, topologicalSortedNodes);
    return topologicalSortedNodes;
}

int main() {
    int n, m;
    int t = 1;
    int c = 3;
    while (true) {
        cin >> n >> m;
        if (!n && !m)
            return 0;
        Graph<T> g(1);
        for (int i = 1; i <= n; i++)
            g.addNode(i);
        int a, b;
        while (m) {
            cin >> a >> b;
            g.addEdge(a, b);
            m--;
        }
        if (hasDirectedCycle(g)) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> toposort = topologicalSort(g);
        for (auto &i : toposort)
            cout << i << endl;
        t++;
    }
    return 0;
}