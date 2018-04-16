#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<int, unordered_set<int>> Graph;

void dfs(int node, Graph &g, unordered_set<int> &visited) {
    for (auto i : g[node]) {
        if (!visited.count(i)) {
            visited.insert(i);
            dfs(i, g, visited);
        }
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            return 0;
        Graph g;
        int u, v;
        while (true) {
            cin >> u;
            if (u == 0)
                break;
            while (true) {
                cin >> v;
                if (v == 0)
                    break;
                g[u].insert(v);
            }
        }
        int m, start;
        cin >> m;
        while (m--) {
            unordered_set<int> visited;
            cin >> start;
            dfs(start, g, visited);
            cout << n - visited.size();
            for (int i = 1; i <= n; i++) {
                if (!visited.count(i))
                    cout << " " << i;
            }
            cout << endl;
        }
    }

}