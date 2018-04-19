typedef int Weight;
typedef pair<int, int> Edge;
typedef pair<Weight, Edge> Wedge;

vector<Wedge> Wedges; // gets filled from input;

vector<Wedge> kruskal() {
    vector<Wedge> mst;
    sort(Wedges.begin(), Wedges.end());
    // reverse(Wedges.begin(), Wedges.end());
    UnionFind uf(n);
    for (Wedge &wedge : Wedges) {
        int u = wedge.second.first, v = wedge.second.second;
        if (!uf.areConnected(u, v))
            uf.join(u, v), mst.push_back(wedge);
    }
    return mst;
}
