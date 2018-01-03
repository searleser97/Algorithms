// uva 315 - Network
#include <bits/stdc++.h>
#include "graphAPI.h"
using namespace std;

typedef int T;

void dfsArticulationPoints(Graph<T> &g, T &node, int &time,
                           unordered_map<T, int> &visitedTime, unordered_map<T, int> &lowTime,
                           vector<T> &articulationPoints, unordered_map<T, T> &parent,
                           unordered_set<T> &visited) {
    visited.insert(node);
    visitedTime[node] = time;
    lowTime[node] = time;
    time++;
    int childCount = 0;
    bool isArticulationPoint = false;
    for (const auto &neighbor : g.nodes[node]) {
        T v = neighbor.first;
        if (v == parent[node])
            continue;
        if (!visited.count(v)) {
            parent[v] = node;
            childCount++;
            dfsArticulationPoints(g, v, time, visitedTime, lowTime, articulationPoints, parent, visited);
            if (visitedTime[node] <= lowTime[v])
                isArticulationPoint = true;
            else
                lowTime[node] = min(lowTime[node], lowTime[v]);
        } else
            lowTime[node] = min(lowTime[node], visitedTime[v]);
    }
    bool isRootNode = parent[node] == node;
    if ((isRootNode && childCount > 1) || (!isRootNode && isArticulationPoint))
        articulationPoints.push_back(node);
}

vector<T> getArticulationPoints(Graph<T> &g) {
    unordered_set<T> visited;
    vector<T> articulationPoints;
    unordered_map<T, int> visitedTime, lowTime;
    unordered_map<T, T> parent;
    T startNode = g.nodes.begin()->first;
    parent[startNode] = startNode;
    int time = 0;
    dfsArticulationPoints(g, startNode, time, visitedTime, lowTime, articulationPoints, parent, visited);
    return articulationPoints;
}

vector<string> split(string str, char token) {
    stringstream test(str);
    string segment;
    vector<std::string> seglist;

    while (std::getline(test, segment, token))
        seglist.push_back(segment);
    return seglist;
}

string input() {
    string ans;
    cin >> ws;
    getline(cin, ans);
    return ans;
}

int main() {
    int N;
    while (true) {
        N = stoi(input());
        if (!N)
            return 0;
        Graph<T> g(0);
        string line;
        while (true) {
            line = input();
            if (line == "0")
                break;
            vector<string> nodes = split(line, ' ');
            T u = stoi(nodes[0]);
            for (int i = 1; i < nodes.size(); i++)
                g.addOrUpdateEdge(u, stoi(nodes[i]));
        }
        cout << getArticulationPoints(g).size() << endl;
    }
    return 0;
}