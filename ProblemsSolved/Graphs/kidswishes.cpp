#include <bits/stdc++.h>

using namespace std;
template <class T> class UnionFind {
public:
    // stores the parent of each node
    unordered_map<T, T> tree;
    // stores the size of each sub-tree
    unordered_map<T, int> treeSize;
    int numberOfSets = 0;

    bool hasNode(T node) {
        return this->tree.count(node);
    }

    void addNode(T newNode) {
        if (!hasNode(newNode)) {
            this->tree[newNode] = newNode;
            this->treeSize[newNode] = 1;
            this->numberOfSets++;
        }
    }

    void addEdge(T v, T w) {
        addNode(v);
        addNode(w);
        T i = setGetRoot(v);
        T j = setGetRoot(w);
        if (i == j)
            return;
        this->numberOfSets--;
        if (treeSize[i] < treeSize[j]) {
            this->tree[i] = j;
            this->treeSize[j] += this->treeSize[i];
        } else {
            this->tree[j] = i;
            this->treeSize[i] += this->treeSize[j];
        }
    }

    bool areNodesConnected(T v, T w) {
        if (!this->tree.count(v) || !this->tree.count(w))
            return false;
        return setGetRoot(v) == setGetRoot(w);
    }

    int getNumberOfSets() {
        return this->numberOfSets;
    }

    int getSizeOfBelongingSubset(T v) {
        if (!this->tree.count(v))
            return 0;
        return this->treeSize[setGetRoot(v)];
    }

private:
    T setGetRoot(T v) {
        while (v != this->tree[v])
            v = this->tree[v] = this->tree[this->tree[v]];
        return v;
    }

};

typedef long long int Long;

int main () {
    while (true) {
        Long k, w;
        cin >> k >> w;
        if (!k && !w)
            return 0;
        unordered_map<Long, Long> bucket;
        unordered_map<int, unordered_map<int, bool>> edges;
        UnionFind<Long> uf;
        Long numberOfCycles = 0LL;
        Long a, b;
        bool flag = false;
        for (Long i = 0LL; i < w; i++) {
            cin >> a >> b;
            if (!flag && !edges[a][b]) {
                if (a != b) {
                    bucket[a]++;
                    bucket[b]++;
                }
                if (uf.areNodesConnected(a, b)) {
                    numberOfCycles++;
                    if (numberOfCycles == 2LL)
                        flag = true;
                }
                uf.addEdge(a, b);
                edges[a][b] = true;
                edges[b][a] = true;
            }
            if (bucket[a] > 2LL || bucket[b] > 2LL)
                flag = true;
        }
        if (flag)
            cout << "N" << endl;
        else if (numberOfCycles == 0LL || (numberOfCycles == 1 && uf.getSizeOfBelongingSubset(a) == k))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}