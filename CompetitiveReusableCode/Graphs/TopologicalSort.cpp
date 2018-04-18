int n; // max node id >= 1
vector<vector<int>> ady; // ady.resize(n + 1)
vector<int> vis; // vis.resize(n + 1)
vector<int> toposorted;

bool toposort(int u) {
    vis[u] = 1;
    for (auto &v : ady[u]) {
        if (v == u || vis[v] == 2)
            continue;
        if (vis[v] == 1 || !toposort(v))
            return false;
    }
    vis[u] = 2;
    toposorted.push_back(u);
    return true;
}

bool toposort() {
    vis.clear();
    for (int u = 1; u <= n; u++)
        if (!vis[u])
            if (!toposort(u))
                return false;
    return true;
}