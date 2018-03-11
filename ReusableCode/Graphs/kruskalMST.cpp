// uva 908 - Re-connecting computer sites
#include <bits/stdc++.h>
#include "graphAPI.h"
#include "unionFind.cpp"
using namespace std;

typedef int T;

double kruskalMST(Graph<T> &g, vector<Edge<T>> &mst) {
    //mst = minimum spanning tree
    double minCost = 0;
    // change '<' to '>' if maximum spanning tree is needed
    auto cmp = [] (const Edge<T> & a, const Edge<T> & b) {return a.weight < b.weight;};
    sort(g.edges.begin(), g.edges.end(), cmp);
    UnionFind<T> uf;
    int limit = g.nodes.size() - 1;
    for (int i = 0; (i < g.edges.size()) && (mst.size() < limit); i++) {
        Edge<T> e = g.edges[i];
        T v = e.v, w = e.w;
        if (!uf.areNodesConnected(v, w)) {
            uf.addEdge(v, w);
            mst.push_back(e);
            minCost += e.weight;
        }
    }
    return minCost;
}

void printv(vector<Edge<T>> v) {
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
        Graph<T> g(0);
        int a, b, cost;
        i--;
        while (i--) {
            cin >> a >> b >> cost;
            g.addEdge(a, b, cost);
        }
        vector<Edge<T>> mst1;
        cout << kruskalMST(g, mst1) << endl;
        Graph<T> g2(0);
        cin >> i;
        while (i--) {
            cin >> a >> b >> cost;
            g2.addEdge(a, b, cost);
        }
        cin >> i;
        while (i--) {
            cin >> a >> b >> cost;
            g2.addEdge(a, b, cost);
        }
        vector<Edge<T>> mst2;
        cout << kruskalMST(g2, mst2) << endl;
        t++;
    }
    return 0;
}