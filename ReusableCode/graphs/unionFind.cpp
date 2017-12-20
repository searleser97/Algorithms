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

/*int main() {
    UnionFind<int> g;
    int a, b;
    int i;
    cin >> i;
    while (i--) {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cin >> i;
    while (i--) {
        cin >> a >> b;
        cout << g.areVertexesConnected(a, b) << '\n';
    }
    return 0;
}*/