#include <bits/stdc++.h>
#include "unionFind.cpp"

using namespace std;

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
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        this->nodes[v][w] = cost;
        this->edges.push_back(Edge(v, w, cost));
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
        this->edges.push_back(Edge(w, v, cost));
    }

public:
    vector<Edge> kruskalMST() {
        //mst = minimum spanning tree
        vector<Edge> mst;
        int minCost = 0;
        // change '<' to '>' if maximum spanning tree is needed
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