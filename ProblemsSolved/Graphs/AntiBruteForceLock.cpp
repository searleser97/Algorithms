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

vector<int> mi = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1};

int minDis(string s1, string s2) {
    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans += mi[abs((s2[i] - '0') - (s1[i] - '0'))];
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> keys(n + 1);
        keys[0] = "0000";
        for (int i = 1; i <= n; i++)
            cin >> keys[i];
        vector<Wedge> Wedges;
        Wedge first;
        first.first = 1 << 30;
        first.second.first = 0;
        for (int i = 0; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                if (!i) {
                    int minia = minDis(keys[i], keys[j]);
                    if (minia < first.first) {
                        first.first = minia;
                        first.second.second = j;
                    }
                } else {
                    Wedges.push_back({minDis(keys[i], keys[j]), {i, j}});
                }
            }

        vector<Wedge> mst;
        int cost = 0;
        sort(Wedges.begin(), Wedges.end());
        UnionFind uf(n + 1);
        for (Wedge &wedge : Wedges) {
            int u = wedge.second.first, v = wedge.second.second;
            if (!uf.areconnected(u, v))
                uf.join(u, v), mst.push_back(wedge), cost += wedge.first;
        }
        cout << cost + first.first << endl;
    }
    return 0;
}