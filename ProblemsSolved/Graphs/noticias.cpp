#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> dad, size;
    int n;
    UnionFind(int N) : n(N), dad(N), size(N, 1) {
        while (--N) dad[N] = N;
    }

    int root(int u) {
        if (dad[u] == u) return u;
        return dad[u] = root(dad[u]);
    }

    bool areConnected(int u, int v) {
        return root(u) == root(v);
    }

    void join(int u, int v) {
        int Ru = root(u), Rv = root(v);
        if (Ru == Rv) return;
        --n;
        if (size[Ru] < size[Rv])
            dad[Ru] = Rv, size[Rv] += size[Ru];
        else
            dad[Rv] = Ru, size[Ru] += size[Rv];
    }

    int getSize(int u) {
        return size[root(u)];
    }

    int numberOfSets() {
        return n;
    }

};

int n, m, u, v;
char ins;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    UnionFind uf(n);
    while(m--) {
        cin >> ins;
        if (ins == 'A') {
            cin >> u >> v;
            uf.join(u, v);
        } if (ins == 'E') {
            cin >> u;
            cout << uf.getSize(u) << endl;
        }
    }
    return 0;
}