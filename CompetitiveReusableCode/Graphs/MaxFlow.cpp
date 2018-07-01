/*
    backward edges keep equilibrium of flow in graph
    they are used as technique to find new paths.
    it also helps by not allowing to find the same path more than once
    in edmons karp algorithm(BFS).

    Ford Fulkerson:
        DFS algorithm.
    Edmons Karp Algorithm:
        Runs BFS repeatedly on residual graph
        each time it finishes a BFS we add to the max-flow the urent max flow found 
        and we update the capacity of each edge (keeping equilibrium) considering backward edges.
    Dinic's Algorithm:
        https://www.slideshare.net/KuoE0/acmicpc-dinics-algorithm
        https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/

    // bottleneck = min(capacity - flow);
    // curpathMaxFlow

    // the 'v' node in blockingFlow dfs is not necessarily one level up
    // because of the updates on backward edges.
*/



#include<bits/stdc++.h>

using namespace std;
// cap[a][b] = Capacity from a to b
// flow[a][b] = flow occupied from a to b
// level[a] = level in graph of node a
// prev[a] = previous node of a

typedef int Num;
vector<int> level;
vector<vector<int>> ady, cap, flow;
bool isBidirectional = false;
int N;

void addEdge(int u, int v, Num capacity) {
    cap[u][v] = capacity;
    ady[u].push_back(v);
}

bool levelGraph(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int &v : ady[u]) {
            if (level[v] < 0 && flow[u][v] < cap[u][v]) {
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
    return level[t] != -1;
}

int blockingFlow(int u, int t, Num currPathMaxFlow, vector<int> &path) {
    path.push_back(u);
    if (u == t) return currPathMaxFlow;
    // cout << "current node: " << u << " pathMaxFlow: " << currPathMaxFlow << endl;
    // cout << "adyacents:" << endl;
    for (int v : ady[u])
        // cout << "    " << v << " cap: " << cap[u][v] << " " << flow[u][v] << endl;
    // cout << endl;
    for (int v : ady[u]) {
        Num capleft = cap[u][v] - flow[u][v];
        // cout << "capleft: " << capleft << endl;
        if ((level[v] == (level[u] + 1)) && (capleft > 0)) {
            // cout << "entro " << currPathMaxFlow << " " << capleft << endl;
            Num pathMaxFlow = blockingFlow(v, t, min(currPathMaxFlow, capleft), path);
            if (pathMaxFlow > 0) {
                flow[u][v] += pathMaxFlow;
                flow[v][u] -= pathMaxFlow;
                return pathMaxFlow;
            }
        }
    }
    return 0;
}

Num dinicMaxFlow(int s, int t) {
    if (s == t) return -1;
    Num maxFlow = 0;
    // int l = 0;
    // while (!l) {
    //     cout << "level: " << ((l = levelGraph(s, t)) ? "true" : "false") << endl;
    //     for (int i = 0; i < level.size(); i++) {
    //         cout << "    " << i << " " << level[i] << endl;
    //     }
    //     while (l) {
    //         vector<int> v;
    //         Num f = blockingFlow(s, t, 1 << 30, v);
    //         cout << "flow: " << f << endl;
    //         for (int i = 0; i < v.size(); i++)
    //             cout << v[i] << " ";
    //         cout << endl;
    //         cin >> l;
    //     }
    // }
    vector<int> v;
    while(levelGraph(s, t))
        while (Num flow = blockingFlow(s, t, 1 << 30, v))
            maxFlow += flow;
    return maxFlow;
}

typedef int Key;
int nextId = 0;

int Map(Key key, unordered_map<int, int> &id) {
    return id.count(key) ? id[key] : id[key] = nextId++;
}

int main() {
    int s, t, c, i = 1;
    while (true) {
        cin >> N;
        if (!N)
            return 0;
        unordered_map<int, int> nodeId;
        nextId = 0;
        ady.resize(N);
        level.resize(N);
        cap.resize(N, vector<int>(N));
        flow.resize(N, vector<int>(N));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        cin >> s >> t >> c;
        while (c--) {
            int u, v, c;
            cin >> u >> v >> c;
            u = Map(u, nodeId);
            v = Map(v, nodeId);
            addEdge(u, v, cap[u][v] + c);
            addEdge(v, u, cap[v][u] + c);
        }
        cout << "Network " << i << endl;
        cout << "The bandwidth is " << dinicMaxFlow(s - 1, t - 1) << "." << endl;
        i++;
    }
    return 0;
}