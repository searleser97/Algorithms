#include<bits/stdc++.h>
using namespace std;

typedef int Num;
typedef pair<Num, int> NodeDist;
int MAXN = 20001, INF = 1 << 30, isDirected = false;
vector<vector<int>> ady(MAXN, vector<int>()),
weight(MAXN, vector<int>(MAXN, INF));

vector<int> dijkstra(int s) {
    vector<int> dist(MAXN, INF);
    set<NodeDist> q;
    q.insert({0, s}); dist[s] = 0;
    while (!q.empty()) {
        NodeDist nd = *q.begin(); q.erase(nd);
        int u = nd.second;
        for (int &v : ady[u]) {
            Num w = weight[u][v];
            if (dist[v] > dist[u] + w) {
                if (dist[v] != INF)
                    q.erase({dist[v], v});
                dist[v] = dist[u] + w;
                q.insert({dist[v], v});
            }
        }
    }
    return dist;
}

void addEdge(int u, int v, Num w) {
    ady[u].push_back(v);
    weight[u][v] = w;
    if (isDirected)
        return;
    ady[v].push_back(u);
    weight[v][u] = w;
}

void initVars() {
    ady = vector<vector<int>>(MAXN, vector<int>());
    weight = vector<vector<int>>(MAXN, vector<int>(MAXN, INF));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Te;
    cin >> Te;
    for (int l = 1; l <= Te; l++) {
        initVars();
        int n, m, s, t, a, b;
        double w;
        cin >> n >> m >> s >> t;
        while (m--) {
            cin >> a >> b >> w;
            addEdge(a, b, w < weight[a][b] ? w : weight[a][b]);
            
        }
        cout << "Case #" << l << ": ";
        vector<int> dist = dijkstra(s);
        if (dist[t] == INF) {
            cout << "unreachable" << endl;
            continue;
        }

        cout << dist[t] << endl;
    }
    return 0;
}