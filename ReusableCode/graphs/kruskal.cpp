#include <bits/stdc++.h>

using namespace std;

template <class T> class UnionFind {
public:
    unordered_map<T, T> tree;
    unordered_map<T, int> treeSize;
    void addEdge(T v, T w) {
        if (!this->tree.count(v)) {
            this->tree[v] = v;
            this->treeSize[v] = 1;
        }
        if (!this->tree.count(w)) {
            this->tree[w] = w;
            this->treeSize[w] = 1;
        }
        T i = setGetRoot(v);
        T j = setGetRoot(w);
        if (i == j)
            return;
        if (treeSize[i] < treeSize[j]) {
            this->tree[i] = j;
            this->treeSize[j] += this->treeSize[i];
        } else {
            this->tree[j] = i;
            this->treeSize[i] += this->treeSize[j];
        }
    }

    bool areVertexesConnected(T v, T w) {
        if (!this->tree.count(v) || !this->tree.count(w))
            return false;
        return setGetRoot(v) == setGetRoot(w);
    }

private:
    T setGetRoot(T v) {
        while (v != this->tree[v]) {
            this->tree[v] = this->tree[this->tree[v]];
            v = this->tree[v];
        }
        return v;
    }

};

class Edge {
public:
    int v, w;
    double weight;
    Edge(int v, int w, double weight) {
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
    vector<Edge> edges;

    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }
    void addEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = cost;
        this->nodes[w][w] = cost;
        this->nodes[v][w] = cost;
        this->edges.push_back(Edge(v, w, cost));
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
        this->edges.push_back(Edge(w, v, cost));
    }

public:
    vector<Edge> kruskalMST() {
        vector<Edge> mst;
        int minCost = 0;
        auto cmp = [] (const Edge & a, const Edge & b) {return a.weight < b.weight;};
        sort(this->edges.begin(), this->edges.end(), cmp);
        UnionFind<T> uf;
        int limit = nodes.size() - 1;
        for (int i = 0; (i < this->edges.size()) && (mst.size() < limit); i++) {
            Edge e = this->edges[i];
            T v = e.v, w = e.w;
            if (!uf.areVertexesConnected(v, w)) {
                uf.addEdge(v, w);
                mst.push_back(e);
                minCost += e.weight;
            }
        }
        cout << minCost << endl;
        return mst;
    }
};


void printv(vector<Edge> v) {
    if (v.size() == 0) {
        cout << "" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].v << " " << v[i].w << " " << v[i].weight << endl;
    }
}

int main() {
    int i;
    int t = 0;
    while (cin >> i) {
        if (t != 0)
            cout << endl;
        auto *g = new Graph<int>(0);
        int a, b, cost;
        i--;
        while (i--) {
            cin >> a >> b >> cost;
            g->addEdge(a, b, cost);
        }
        g->kruskalMST();
        delete g;
        g = new Graph<int>(0);
        cin >> i;
        while (i--) {
            cin >> a >> b >> cost;
            g->addEdge(a, b, cost);
        }
        cin >> i;
        while (i--) {
            cin >> a >> b >> cost;
            g->addEdge(a, b, cost);
        }
        g->kruskalMST();
        t++;
    }
    return 0;
}