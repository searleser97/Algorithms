int n; // max node id >= 1
vector<vector<int>> ady; // ady.resize(n + 1)
vector<bool> vis; // vis.resize(n + 1)
vector<vector<int>> cycles;
vector<int> cycle;
bool flag = false;
int rootNode = -1;

bool hasUndirectedCycle(int u, int prev) {
    vis[u] = true;
    for (auto &v : ady[u]) {
        if (v == u || v == prev)
            continue;
        if (vis[v] || hasUndirectedCycle(v, u)) {
            if (rootNode == -1)
                rootNode = v, flag = true;
            if (flag) {
                cycle.push_back(u);
                if (rootNode == u)
                    flag = false;
            }
            return true;
        }
    }
    return false;
}

bool hasUndirectedCycle() {
    vis.clear();
    for (int u = 1; u <= n; u++)
        if (!vis[u]) {
            cycle.clear();
            if (hasUndirectedCycle(u, -1))
                cycles.push_back(cycle);
        }
    return cycles.size() > 0;
}