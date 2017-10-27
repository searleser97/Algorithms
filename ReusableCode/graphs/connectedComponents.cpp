#include <bits/stdc++.h>

using namespace std;
typedef char T;
class Graph {
public:
    unordered_map<T, unordered_map<T, bool> > edges;

    void addEdge(T v, T w) {
        this->edges[v][w] = true;
        this->edges[w][v] = true;
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
    char n;
    while (cin >> n) {
        cin.ignore();
        Graph g;
        while (true) {
            g.addEdge(n, n);
            if (n == 'A')
                break;
            n--;
        }
        string edge;
        while (getline(cin, edge)) {
            if (edge == "")
                break;
            g.addEdge(edge[0], edge[1]);
        }
        /*vector<vector<T>> connectedComponents = g.getConnectedComponents();
        for (auto vertexes : connectedComponents) {
            printv(vertexes);
        }*/
        cout << g.getConnectedComponents().size() << "\n";
        cout << g.isEdgeInGraph('A', 'B') << "\n";
        cout << g.isEdgeInGraph('C', 'A') << "\n";
    }

    return 0;
}