int n; // max node id >= 1
vector<vector<int>> ady; // ady.resize(n + 1)

bool isBipartite() {
    vector<int> color(n + 1, -1);
    for (int s = 1; s <= n; s++) {
        if (color[s] > -1)
            continue;
        color[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int &v : ady[u]) {
                if (color[v] < 0)
                    q.push(v), color[v] = !color[u];
                if (color[v] == color[u])
                    return false;
            }
        }
    }
    return true;
}