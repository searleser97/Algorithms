#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> dad, size;
    int n;

    UnionFind(int N) : n(N), dad(N), size(N, 1) {
        while (--N) dad[N] = N;
    }
    int root (int u) {
        if (dad[u] == u) return u;
        return dad[u] = root(dad[u]);
    }

    bool areconnected(int u, int v) {
        return root(u) == root(v);
    }

    void join(int u, int v) {
        int Ru = root(u), Rv = root(v);
        if (Ru == Rv) return;
        --n, dad[Ru] = Rv;
        size[Rv] += size[Ru];
    }

    int getSize(int u) {
        return size[root(u)];
    }

    int numberOfSets() {
        return n;
    }

};

typedef int Weight;
typedef pair<int, int> Edge;
typedef pair<Weight, Edge> Wedge;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (!n && !m)
            return 0;
        vector<Wedge> Wedges;
        int totalCost = 0;
        for (int i = 0; i < m; i++) {
            int u, v; int c;
            cin >> u >> v >> c;
            Wedges.push_back({c, {u, v}});
            totalCost += c;
        }
        vector<Wedge> mst;
        int cost = 0;
        sort(Wedges.begin(), Wedges.end());
        UnionFind uf(n);
        for (Wedge &wedge : Wedges) {
            int u = wedge.second.first, v = wedge.second.second;
            if (!uf.areconnected(u, v))
                uf.join(u, v), mst.push_back(wedge), cost += wedge.first;
        }
        cout << totalCost - cost << endl;
    }
    return 0;
}