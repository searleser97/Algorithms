// uva 459 - graph connectivity
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef char T;

void dfsCC(Graph<T> &g, vector<T> &component, unordered_map<T, int> &nodeComponentIds, unordered_set<T> &visited, T actualNodeId, int &componentId) {
    visited.insert(actualNodeId);
    nodeComponentIds[actualNodeId] = componentId;
    component.push_back(actualNodeId);
    for (auto neighbor : g.nodes[actualNodeId])
        if (!visited.count(neighbor.first))
            dfsCC(g, component, nodeComponentIds, visited, neighbor.first, componentId);
}

pair<vector<vector<T>>, unordered_map<T, int>> getConnectedComponents(Graph<T> &g) {
    unordered_map<T, int> nodeComponentIds;
    vector<vector<T>> connectedComponents;
    unordered_set<T> visited;
    int componentId = 1;
    for (auto node : g.nodes)
        if (!visited.count(node.first)) {
            vector<T> component;
            dfsCC(g, component, nodeComponentIds, visited, node.first, componentId);
            connectedComponents.push_back(component);
            componentId++;
        }
    return {connectedComponents, nodeComponentIds};
}

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
        Graph<T> g;
        string highest;
        highest = input();
        for (T i = highest[0]; i >= 'A'; i--)
            g.addNode(i);
        while (true) {
            string edge = input();
            if (edge == "")
                break;
            g.addEdge(edge[0], edge[1]);
        }
        pair<vector<vector<T>>, unordered_map<T, int>> connectedComponents = getConnectedComponents(g);
        cout << connectedComponents.first.size() << endl;
        if (t != 0)
            cout << endl;
    }
    return 0;
}