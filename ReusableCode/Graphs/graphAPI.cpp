#include <bits/stdc++.h>
#include "unionFind.cpp"
#include "indexedPriorityQueue.cpp"

using namespace std;

double INF = 1 << 30;

class Edge {
public:
    int v, w;
    double weight;
    Edge(int v, int w, double weight = 0) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
};

template <class T> class Graph {
public:
    //node -> value , neighbors -> value, weight
    unordered_map<T, unordered_map<T, double> > nodes;
    bool isDirectedGraph;
    UnionFind<T> uf;
    vector<Edge> edges;

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
        this->edges.push_back(Edge(v, w, cost));
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = cost;
        this->edges.push_back(Edge(w, v, cost));
        uf.addEdge(v, w);
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

private:
    void dfsCC(vector<T> &component, unordered_map<T, int> &nodeComponentIds, unordered_set<T> &visited, T actualNodeId, int &componentId) {
        visited.insert(actualNodeId);
        nodeComponentIds[actualNodeId] = componentId;
        component.push_back(actualNodeId);
        for (auto neighbor : this->nodes[actualNodeId])
            if (!visited.count(neighbor.first))
                dfsCC(component, nodeComponentIds, visited, neighbor.first, componentId);
    }

public:
    pair<vector<vector<T>>, unordered_map<T, int>> getConnectedComponents() {
        unordered_map<T, int> nodeComponentIds;
        vector<vector<T>> connectedComponents;
        unordered_set<T> visited;
        int componentId = 1;
        for (auto node : this->nodes)
            if (!visited.count(node.first)) {
                vector<T> component;
                dfsCC(component, nodeComponentIds, visited, node.first, componentId);
                connectedComponents.push_back(component);
                componentId++;
            }
        return {connectedComponents, nodeComponentIds};
    }

    bool areNodesConnected(T v, T w) {
        return this->uf.areVertexesConnected(v, w);
    }

private:
    void dfsTopologicalSort(unordered_map<T, double> neighbors, int &index, unordered_set<T> &visited, vector<T> &topologicalSortedNodes) {
        for (auto neighbor : neighbors) {
            if (!visited.count(neighbor.first)) {
                visited.insert(neighbor.first);
                dfsTopologicalSort(this->nodes[neighbor.first], index, visited, topologicalSortedNodes);
                topologicalSortedNodes[index] = neighbor.first;
                index--;
            }
        }
    }

public:
    vector<T> topologicalSort() {
        if (!this->isDirectedGraph) {
            vector<T> trash;
            return trash;
        }
        unordered_set<T> visited;
        vector<T> topologicalSortedNodes(this->nodes.size());
        int index = this->nodes.size() - 1;
        for (auto edge : this->nodes) {
            if (!visited.count(edge.first)) {
                visited.insert(edge.first);
                dfsTopologicalSort(edge.second, index, visited, topologicalSortedNodes);
                topologicalSortedNodes[index] = edge.first;
                index--;
            }
        }
        return topologicalSortedNodes;
    }

    double kruskalMST(vector<Edge> &mst) {
        //mst = minimum spanning tree
        double minCost = 0;
        // change '<' to '>' if maximum spanning tree is needed
        auto cmp = [] (const Edge & a, const Edge & b) {return a.weight < b.weight;};
        sort(this->edges.begin(), this->edges.end(), cmp);
        UnionFind<T> uf;
        int limit = nodes.size() - 1;
        for (int i = 0; (i < this->edges.size()) && (mst.size() < limit); i++) {
            Edge e = this->edges[i];
            T v = e.v, w = e.w;
            if (!uf.areVertexesConnected(v, w)) {
                uf.addEdge(v, w);
                mst.push_back(e);
                minCost += e.weight;
            }
        }
        return minCost;
    }

    void dijkstra(unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
        indexedPriorityQueue<T> ipq;
        for (auto node : nodes) {
            ipq.push(node.first, INF);
        }
        ipq.update(source, 0);
        distances[source] = 0;
        parents[source] = source;
        while (!ipq.empty()) {
            auto current = ipq.pop();
            distances[current.first] = current.second;
            for (auto neighbor : nodes[current.first]) {
                if (!ipq.containsKey(neighbor.first))
                    continue;
                double newDistance = distances[current.first] + neighbor.second;
                if (ipq.getWeight(neighbor.first) > newDistance) {
                    ipq.update(neighbor.first, newDistance);
                    parents[neighbor.first] = current.first;
                }
            }
        }
    }

    bool bellmanFord(unordered_map<T, double> &distances, unordered_map<T, T> &parents, T source) {
        queue<T> q;
        unordered_set<T> in_queue;
        unordered_map<T, int> ocurrenceOfNodeInQueue;
        for (auto node : nodes) {
            distances[node.first] = INF;
            parents[node.first] = node.first;
        }
        distances[source] = 0;
        q.push(source);
        int limit = nodes.size() - 1;
        in_queue.insert(source);
        ocurrenceOfNodeInQueue[source] += 1;
        while (!q.empty()) {
            T u = q.front(); q.pop(); in_queue.erase(u);
            for (auto neighbor : nodes[u]) {
                T v = neighbor.first;
                double newDistance = distances[u] + neighbor.second;
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    parents[v] = u;
                    if (!in_queue.count(v)) {
                        q.push(v);
                        ocurrenceOfNodeInQueue[v] += 1;
                        if (ocurrenceOfNodeInQueue[v] > limit)
                            return false;
                    }
                }
            }
        }
        return true;
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
private:
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

private:
    bool hasUndirectedCycle(T node, T prevNode, unordered_set<T> &visited) {
        visited.insert(node);
        for (auto neighbor : this->nodes[node]) {
            if (neighbor.first == node || neighbor.first == prevNode)
                continue;
            if (visited.count(neighbor.first))
                return true;
            if (hasUndirectedCycle(neighbor.first, node, visited))
                return true;
        }
        return false;
    }
public:
    bool hasUndirectedCycle() {
        unordered_set<T> visited;
        for (auto node : this->nodes)
            if (!visited.count(node.first)) {
                if (hasUndirectedCycle(node.first, node.first, visited))
                    return true;
            }
        return false;
    }
private:
    bool hasDirectedCycle(T node, T prevNode, unordered_map<T, int> &visited) {
        visited[node] = 1;
        for (auto neighbor : this->nodes[node]) {
            T v = neighbor.first;
            if (v == node || v == prevNode || visited[v] == 2)
                continue;
            if (visited[v] == 1)
                return true;
            if (hasDirectedCycle(v, node, visited))
                return true;
        }
        visited[node] = 2;
        return false;
    }
public:
    bool hasDirectedCycle() {
        unordered_map<T, int> visited;
        for (auto node : this->nodes)
            if (!visited[node.first])
                if (hasDirectedCycle(node.first, node.first, visited))
                    return true;
        return false;
    }
};

int main() {
    return 0;
}