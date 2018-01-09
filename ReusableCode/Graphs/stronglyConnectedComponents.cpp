// uva 247 - Calling Circles
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef string T;

void dfsStronglyConnectedComponents(Graph<T> &g, T node, int &time,
                                    unordered_map<T, int> &visitedTime, unordered_map<T, int> &lowTime,
                                    vector<vector<T>> &stronglyConnectedComponents, stack<T> &Stack,
                                    unordered_set<T> &inStack, unordered_set<T> &visited) {
    visited.insert(node);
    visitedTime[node] = time;
    lowTime[node] = time;
    time++;
    Stack.push(node);
    inStack.insert(node);
    for (const auto &neighbor : g.nodes[node]) {
        T v = neighbor.first;
        if (!visited.count(v)) {
            dfsStronglyConnectedComponents(g, v, time, visitedTime, lowTime, stronglyConnectedComponents, Stack, inStack, visited);
            lowTime[node] = min(lowTime[node], lowTime[v]);
        } else if (inStack.count(v))
            lowTime[node] = min(lowTime[node], visitedTime[v]);
    }
    if (visitedTime[node] == lowTime[node]) {
        vector<T> stronglyConnectedComponent;
        T u;
        while (true) {
            u = Stack.top(); Stack.pop();
            inStack.erase(u);
            stronglyConnectedComponent.push_back(u);
            if (u == node)
                break;
        }
        stronglyConnectedComponents.push_back(stronglyConnectedComponent);
    }
}

vector<vector<T>> getStronglyConnectedComponents(Graph<T> &g) {
    unordered_set<T> visited;
    vector<vector<T>> stronglyConnectedComponents;
    unordered_map<T, int> visitedTime, lowTime;
    unordered_set<T> inStack;
    stack<T> Stack;
    int time = 0;
    for (const auto &node : g.nodes)
        if (!visited.count(node.first))
            dfsStronglyConnectedComponents(g, node.first, time, visitedTime, lowTime, stronglyConnectedComponents, Stack, inStack, visited);
    return stronglyConnectedComponents;
}


int main() {
    int n, m, nT = 1;
    while (true) {
        cin >> n >> m;
        if (!n && !m)
            return 0;
        if (nT != 1)
            cout << endl;
        Graph<T> g(1);
        string from, to;
        while (m--) {
            cin >> from >> to;
            g.addEdge(from, to);
        }

        vector<vector<T>> scc = getStronglyConnectedComponents(g);
        cout << "Calling circles for data set " << nT << ":" << endl;
        for (int i = 0; i < scc.size(); i++) {
            cout << scc[i][0];
            for (int j = 1; j < scc[i].size(); j++)
                cout << ", " << scc[i][j];
            cout << endl;
        }
        nT++;
    }
    return 0;
}