#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> Graph(301, vector<int>());
unordered_set<int> visited;

int dfs(int node) {
    cout << node << endl;
    if (visited.count(node))
        return 0;
    visited.insert(node);
    int count = 1;
    for (auto & adj : Graph[node]) {
        count += dfs(adj);
    }
    return count;
}

int main() {
    int n;
    while(cin >> n) {
        int a, b, N = n;
        while(true) {
            cin >> a >> b;
            if (!a && !b)
                break;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if ((dfs(i) % 4) != 0)
                cout << "NO" << endl;
        }
        cout << "YES" << endl;
    }
}