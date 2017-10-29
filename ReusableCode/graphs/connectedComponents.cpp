#include <bits/stdc++.h>

using namespace std;
typedef int T;
class Graph {
public:
    unordered_map<T, unordered_map<T, bool> > edges;
    unordered_map<T, T> tree;
    unordered_map<T, int> treeSize;
    void addEdge(T v, T w) {
        this->edges[v][v] = true;
        this->edges[w][w] = true;
        this->edges[v][w] = true;
        this->edges[w][v] = true;
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

    void dfs(unordered_map<T, bool> &vertexes, unordered_map<T, bool> &visited, vector<T> &connectedComponents) {
        for (auto vertex : vertexes) {
            if (!visited.count(vertex.first)) {
                connectedComponents.push_back(vertex.first);
                visited[vertex.first] = true;
                dfs(this->edges[vertex.first], visited, connectedComponents);
            }
        }
    }

    vector< vector<T> > getConnectedComponents() {
        unordered_map<T, bool> visited;
        vector< vector<T> > connectedComponents;
        for (auto edge : this->edges) {
            if (!visited.count(edge.first)) {
                vector<T> vertexes;
                vertexes.push_back(edge.first);
                visited[edge.first] = true;
                dfs(this->edges[edge.first], visited, vertexes);
                connectedComponents.push_back(vertexes);
            }
        }
        return connectedComponents;
    }

    bool isEdgeInGraph(T v, T w) {
        return this->edges.count(v) ? this->edges[v].count(w) : false;
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