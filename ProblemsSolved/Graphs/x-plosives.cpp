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

vector<int> us;
vector<int> vs;

int main() {
    int maxx = 0, ans = 0;
    int u, v;
    while (cin >> u) {
        if (u == -1) {
            UnionFind uf(500000);
            for (int i = 0; i < us.size(); i++) {
                if (uf.areConnected(us[i], vs[i]))
                    ans++;
                else
                    uf.join(us[i], vs[i]);
            }
            cout << ans << endl;
            ans = 0;
            us.clear();
            vs.clear();
            maxx = 0;
        } else {
            cin >> v;
            us.push_back(u);
            vs.push_back(v);
        }
    }
    return 0;
}