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

/*
    PROBLEM:
        determine max flow of a bidirectional graph where 
        the capacity of u to v is the capacity for v to u;
*/

// cap[a][b] = Capacity from a to b
// flow[a][b] = flow occupied from a to b
// level[a] = level in graph of node a
// prev[a] = previous node of a



#include<bits/stdc++.h>

using namespace std;

typedef int Num;
vector<int> level;
vector<vector<int>> ady, cap, flow;
int N;
int MAXN = 101;

void addEdge(int u, int v, Num capacity) {
    cap[u][v] = capacity;
    ady[u].push_back(v);
}

bool levelGraph(int s, int t) {
    level = vector<int>(MAXN);
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

int blockingFlow(int u, int t, Num currPathMaxFlow) {
    if (u == t) return currPathMaxFlow;
    for (int v : ady[u]) {
        Num capleft = cap[u][v] - flow[u][v];
        if ((level[v] == (level[u] + 1)) && (capleft > 0)) {
            Num pathMaxFlow = blockingFlow(v, t, min(currPathMaxFlow, capleft));
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
    while(levelGraph(s, t))
        while (Num flow = blockingFlow(s, t, 1 << 30))
            maxFlow += flow;
    return maxFlow;
}

// -----------------

typedef int Key;
unordered_map<int, int> id;
int nextId = 0;

int Map(Key key) {
    return id.count(key) ? id[key] : id[key] = nextId++;
}

void initMapping() {
    nextId = 0;
    id.clear();
}

void initVars() {
    initMapping();
    ady = vector<vector<int>>(MAXN, vector<int>());
    cap = vector<vector<int>>(MAXN, vector<int>(MAXN));
    flow = vector<vector<int>>(MAXN, vector<int>(MAXN));
}

// -----------------

int main() {
    int s, t, c, i = 1;
    while (true) {
        cin >> N;
        if (!N)
            return 0;      
        initVars();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
        cin >> s >> t >> c;
        while (c--) {
            int a, b, c;
            cin >> a >> b >> c;
            Key u = Map(a);
            Key v = Map(b);
            addEdge(u, v, cap[u][v] + c);
            addEdge(v, u, cap[v][u] + c);
        }
        cout << "Network " << i << endl;
        cout << "The bandwidth is " << dinicMaxFlow(Maps(s), Maps(t)) << "." << endl;
        cout << endl;
        i++;
    }
    return 0;
}