#include <bits/stdc++.h>
// #include "indexedPriorityQueue.cpp"

using namespace std;

template <typename T> class indexedPriorityQueue {
private:
    class Node {
    public:
        double weight;
        T key;
    };
    vector<Node> pq;
    unordered_map<T, int> nodePosition;

private:
    void updatePositionInMap(T key1, T key2, int pos1, int pos2) {
        this->nodePosition[key1] = pos1;
        this->nodePosition[key2] = pos2;
    }
public:
    bool containsKey(T key) {
        return this->nodePosition.count(key);
    }

    T top() {
        return this->pq[0].key;
    }

    bool empty() {
        return this->pq.size() == 0;
    }

    void push(T key, int weight) {
        Node node;
        node.weight = weight;
        node.key = key;
        this->pq.push_back(node);
        int current = this->pq.size() - 1;
        int parentIndex = (current - 1) / 2;
        this->nodePosition[node.key] = current;
        while (parentIndex > -1) {
            Node parentNode = this->pq[parentIndex];
            Node currentNode = this->pq[current];
            // use '>' for minHeap, use '<' for maxheap
            if (parentNode.weight > currentNode.weight) {
                swap(this->pq[parentIndex], this->pq[current]);
                updatePositionInMap(this->pq[parentIndex].key, this->pq[current].key, parentIndex, current);
                current = parentIndex;
                parentIndex = (current - 1) / 2;
            } else
                break;
        }
    }

    void update(T key, int newWeight) {
        if (!this->nodePosition.count(key))
            return;
        int pos = this->nodePosition[key];
        this->pq[pos].weight = newWeight;
        int parent = (pos - 1) / 2;
        while (parent > - 1) {
            // use '>' for minHeap, use '<' for maxheap
            if (this->pq[parent].weight > this->pq[pos].weight) {
                swap(this->pq[parent], this->pq[pos]);
                updatePositionInMap(this->pq[parent].key, this->pq[pos].key, parent, pos);
                pos = parent;
                parent = (pos - 1) / 2;
            } else
                break;
        }
    }

    double getWeight(T key) {
        if (!this->nodePosition.count(key))
            return -1;
        return this->pq[this->nodePosition[key]].weight;
    }

    pair<T, double> pop() {
        int lastPos = this->pq.size() - 1;
        Node topNode = this->pq[0];
        this->pq[0] = this->pq[lastPos];
        this->nodePosition.erase(topNode.key);
        this->nodePosition[this->pq[0].key] = 0;
        this->pq.erase(pq.begin() + lastPos);
        int currentPos = 0;
        lastPos--;
        while (true) {
            int left = 2 * currentPos + 1;
            int right = left + 1;
            if (left > lastPos)
                break;
            if (right > lastPos)
                right = left;
            // in case of using maxheap, smallerPos will haver the biggerPos value
            // use '>' for minHeap, use '<' for maxheap
            int smallerPos = this->pq[right].weight > this->pq[left].weight ? left : right;
            // use '>' for minHeap, use '<' for maxheap
            if (this->pq[currentPos].weight > this->pq[smallerPos].weight) {
                swap(this->pq[currentPos], this->pq[smallerPos]);
                updatePositionInMap(this->pq[currentPos].key, this->pq[smallerPos].key, currentPos, smallerPos);
                currentPos = smallerPos;
            } else
                break;
        }
        return {topNode.key, topNode.weight};
    }

    void printPositionInMap () {
        cout << "{ ";
        for (auto i : this->nodePosition)
            cout << i.first << "=" << i.second << ",";
        cout << " }" << endl;
    }

    void printHeap () {
        for (Node n : this->pq)
            cout << n.weight << " " << n.key << endl;
    }

};

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
    void addEdge(T v, T w, double cost = 0) {
        this->nodes[v][v] = 0;
        this->nodes[w][w] = 0;
        // consider the smallest edge in case of duplicates
        if (!(this->nodes.count(v) && this->nodes[v].count(w)) || (cost < this->nodes[v][w]))
            this->nodes[v][w] = cost;
        if (isDirectedGraph)
            return;
        this->nodes[w][v] = this->nodes[v][w];
    }

    unordered_map<T, double> dijkstra(T source) {
        indexedPriorityQueue<T> ipq;
        unordered_map<T, double> distances;
        unordered_map<T, T> parents;
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
        return distances;
    }
};

void printMap (unordered_map<int, double> m) {
    cout << "{ ";
    for (auto i : m)
        cout << i.first << "=" << i.second << ",";
    cout << " }" << endl;
}

int main() {
    double INF = 1 << 30;
    int T;
    cin >> T;
    for (int l = 1; l <= T; l++) {
        int n, m, s, t, a, b;
        double w;
        cin >> n >> m >> s >> t;
        Graph<int> g(0);
        while (m--) {
            cin >> a >> b >> w;
            g.addEdge(a, b, w);
        }
        cout << "Case #" << l << ": ";
        unordered_map<int, double> distances = g.dijkstra(s);
        
        if (!distances.count(t)) {
            cout << "unreachable" << endl;
            continue;
        }
        
        if (distances[t] == INF) {
            cout << "unreachable" << endl;
            continue;
        }

        cout << distances[t] << endl;
    }
    return 0;
}