#include <bits/stdc++.h>

using namespace std;
template <class T> class CC {
public:
    //node -> id , neighbors
    unordered_map<T, unordered_set<T> > nodes;

    void addEdge(T v, T w) {
        this->nodes[v].insert(v);
        this->nodes[w].insert(w);
        this->nodes[v].insert(w);
        this->nodes[w].insert(v);
    }

private:
    void dfsCC(vector<T> &component, unordered_map<T, int> &nodeComponentIds, unordered_set<T> &visited, T actualNodeId, int &componentId) {
        visited.insert(actualNodeId);
        nodeComponentIds[actualNodeId] = componentId;
        component.push_back(actualNodeId);
        for (auto neighborId : this->nodes[actualNodeId])
            if (!visited.count(neighborId))
                dfsCC(component, nodeComponentIds, visited, neighborId, componentId);
    }

public:
    pair<vector<vector<T>>, unordered_map<T, int>> getConnectedComponents() {
        unordered_map<T, int> nodeComponentIds;
        vector<vector<T>> connectedComponents;
        unordered_set<T> visited;
        int componentId = 1;
        for (auto node : this->nodes) {
            if (!visited.count(node.first)) {
                vector<T> component;
                dfsCC(component, nodeComponentIds, visited, node.first, componentId);
                connectedComponents.push_back(component);
                componentId++;
            }
        }
        return {connectedComponents, nodeComponentIds};
    }
};

string input() {
    string str;
    getline(cin, str);
    return str;
}

int main() {
    int t;
    t = stoi(input());
    input();
    while (t--) {
        CC<char> g;
        string highest;
        highest = input();
        for (char i = highest[0]; i >= 'A'; i--)
            g.addEdge(i, i);
        while (true) {
            string edge = input();
            if (edge == "")
                break;
            g.addEdge(edge[0], edge[1]);
        }
        pair<vector<vector<char>>, unordered_map<char, int>> connectedComponents = g.getConnectedComponents();
        cout << connectedComponents.first.size() << endl;
        if (t != 0)
            cout << endl;
    }
    return 0;
}