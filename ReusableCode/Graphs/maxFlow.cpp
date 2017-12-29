#include <bits/stdc++.h>

using namespace std;

template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    double INF = 1 << 30;
    // 0 -> undirected, 1 -> directed
    Graph(bool isDirectedGraph = false) {
        this->isDirectedGraph = isDirectedGraph;
    }

    unordered_map<T, unordered_map<T, double> > getNodes() {
        return this->nodes;
    }

    void addOrUpdateEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
    }

    bool hasEdge(T v, T w) {
        return this->nodes.count(v) ? this->nodes[v].count(w) : false;
    }

    double getEdgeWeight(T v, T w) {
        if (hasEdge(v, w))
            return this->nodes[v][w];
        return 0;
    }

    void printEdges() {
        for (auto node : this->nodes) {
            T u = node.first;
            for (auto neighbor : this->nodes[u]) {
                cout << u << " " << neighbor.first << " " << neighbor.second << endl;
            }
        }
    }

    double maxFlow(vector<vector<T>> &paths, T source, T target) {
        Graph<T> residualGraph(1);
        residualGraph.nodes = this->nodes;
        double max_flow = 0;
        unordered_map<T, T> parent;
        while (hasAugmentedPath(residualGraph, parent, source, target)) {
            vector<T> path;
            double flow = INF;
            T v = target;
            while (v != source) {
                T u = parent[v];
                if (flow > residualGraph.getEdgeWeight(u, v))
                    flow = residualGraph.getEdgeWeight(u, v);
                path.push_back(v);
                v = u;
            }
            path.push_back(source);
            reverse(path.begin(), path.end());
            paths.push_back(path);
            max_flow += flow;
            v = target;
            while (v != source) {
                T u = parent[v];
                residualGraph.addOrUpdateEdge(u, v, residualGraph.getEdgeWeight(u, v) - flow);
                residualGraph.addOrUpdateEdge(v, u, residualGraph.getEdgeWeight(v, u) + flow);
                v = u;
            }
        }
        return max_flow;
    }

    bool hasAugmentedPath(Graph<T> &residualGraph, unordered_map<T, T> &parent, T source, T target) {
        queue<T> q;
        q.push(source);
        unordered_set<T> visited;
        visited.insert(source);
        while (!q.empty()) {
            T current = q.front(); q.pop();
            for (auto neighbor : residualGraph.nodes[current]) {
                T v = neighbor.first;
                if (!visited.count(v) && neighbor.second > 0) {
                    q.push(v);
                    visited.insert(v);
                    parent[v] = current;
                    if (v == target)
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int i = 1, n, s, t, c, u, v;
    double w;
    while (true) {
        Graph<int> g(0);
        cin >> n;
        if (!n)
            break;
        cin >> s >> t >> c;
        while (c--) {
            cin >> u >> v >> w;
            g.addOrUpdateEdge(u, v, g.getEdgeWeight(u, v) + w);
        }
        vector<vector<int>> parents;
        cout << "Network " << i << endl;
        cout << "The bandwidth is " << g.maxFlow(parents, s, t) << "." << endl;
        cout << endl;
        i++;
    }
    return 0;
}