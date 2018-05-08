#include<bits/stdc++.h>

using namespace std;

int n; // max node id >= 1
vector<vector<int>> ady; // ady.resize(n + 1)
vector<int> cuenta(2);
int ans = 0;

bool isBipartite() {
    vector<int> color(n, -1);
    for (int s = 0; s < n; s++) {
        cuenta[0] = 0, cuenta[1] = 0;
        if (color[s] > -1)
            continue;
        color[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cuenta[color[u]]++;
            for (int &v : ady[u]) {
                if (color[v] < 0)
                    q.push(v), color[v] = !color[u];
                if (color[v] == color[u])
                    return false;
            }
        }
        ans += max(1, min(cuenta[0], cuenta[1]));
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        int m;
        cin >> n >> m;
        ady = vector<vector<int>>(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            ady[u].push_back(v);
            ady[v].push_back(u);
        }

        if (isBipartite())
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}