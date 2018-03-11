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
        if (!hasNode(v)) addNode(v);
        if (!hasNode(w)) addNode(w);
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