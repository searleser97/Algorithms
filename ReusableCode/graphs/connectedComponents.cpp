#include <bits/stdc++.h>

using namespace std;
typedef int T;
class Graph {
public:
    //node -> value , neighbors
    unordered_map<T, unordered_set<T> > nodes;
    unordered_map<T, T> tree;
    unordered_map<T, int> treeSize;
    void addEdge(T v, T w) {
        this->nodes[v].insert(v);
        this->nodes[w].insert(w);
        this->nodes[v].insert(w);
        this->nodes[w].insert(v);
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

private:
    void dfs(unordered_set<T> &vertexesInComponent, unordered_set<T> &visited, vector<T> &connectedComponents) {
        for (auto vertex : vertexesInComponent) {
            if (!visited.count(vertex)) {
                connectedComponents.push_back(vertex);
                visited.insert(vertex);
                dfs(this->nodes[vertex], visited, connectedComponents);
            }
        }
    }

public:
    vector< vector<T> > getConnectedComponents() {
        unordered_set<T> visited;
        vector< vector<T> > connectedComponents;
        for (auto edge : this->nodes) {
            if (!visited.count(edge.first)) {
                vector<T> vertexesInComponent;
                vertexesInComponent.push_back(edge.first);
                visited.insert(edge.first);
                dfs(edge.second, visited, vertexesInComponent);
                connectedComponents.push_back(vertexesInComponent);
            }
        }
        return connectedComponents;
    }

    bool isEdgeInGraph(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
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


void printv(vector<T> v) {
    if (v.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << ", " << v[i];
    }
    cout << "]" << endl;
}


int main() {
    Graph g;
    T a, b;
    int i;
    cin >> i;
    while (i--) {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    for (auto v : g.getConnectedComponents()) {
        printv(v);
    }
    cin >> i;
    while (i--) {
        cin >> a >> b;
        cout << g.areVertexesConnected(a, b) << '\n';
    }
    return 0;
}