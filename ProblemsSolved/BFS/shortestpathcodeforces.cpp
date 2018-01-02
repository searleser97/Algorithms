//http://codeforces.com/contest/59/problem/E
#include <bits/stdc++.h>

using namespace std;

bool isProhibited(unordered_map<int, unordered_map<int, unordered_set<int>>> &prohibitedTrie, int a, int b, int c) {
    return prohibitedTrie[a][b].count(c);
}

struct NodeParent {
    int parent;
    int node;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, unordered_set<NodeParent*>> graph;
    unordered_map<int, unordered_map<int, unordered_set<int>>> prohibitedTrie;

    while (m--) {
        int x, y;
        cin >> x >> y;
        NodeParent* edge1 = new NodeParent();
        edge1->parent = x;
        edge1->node = y;
        NodeParent* edge2 = new NodeParent();
        edge2->parent = y;
        edge2->node = x;
        graph[x].insert(edge1);
        graph[y].insert(edge2);
    }

    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        prohibitedTrie[a][b].insert(c);
    }
    deque<NodeParent*> queue_;
    unordered_map<NodeParent*, NodeParent*> previous;
    unordered_set<NodeParent*> visited;
    NodeParent* aux = new NodeParent();
    aux->parent = 0;
    aux->node = 0;
    NodeParent* start = new NodeParent();
    start->parent = 0;
    start->node = 1;
    queue_.push_back(start);
    previous[aux] = aux;
    previous[start] = aux;
    visited.insert(start);
    while (queue_.size() != 0) {
        NodeParent* current = queue_.front();
        queue_.pop_front();
        if (current->node == n) {
            stack<int> tmp;
            while (current->node != 0) {
                tmp.push(current->node);
                current = previous[current];
            }

            cout << tmp.size() - 1 << endl;
            while (!tmp.empty()) {
                cout << tmp.top() << " ";
                tmp.pop();
            }
            cout << endl;
            return 0;
        }

        for (auto neighbor : graph[current->node])
            if (!visited.count(neighbor) && !isProhibited(prohibitedTrie, current->parent, current->node, neighbor->node)) {
                visited.insert(neighbor);
                queue_.push_back(neighbor);
                previous[neighbor] = current;
            }
    }

    cout << -1 << endl;

    return 0;
}