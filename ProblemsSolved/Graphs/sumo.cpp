#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> ady;
vector<int> color;

bool isBipartite() {
    
    for (int s = 1; s <= n; s++) {
        if (color[s] > -1)
            continue;
        color[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()) { 
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    ady.resize(n + 1);
    color = vector<int>(n + 1, -1);
    
    vector<int> us(m);
    vector<int> vs(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        us[i] = u;
        vs[i] = v;
    }
    
    int left = 1, right = m, middle = 0;
    int limit = 20;
    while (limit--) {
        middle = (left + right) / 2;
        for (int i = 1; i <= n; i++)
            ady[i].clear(), color[i] = -1;
        for (int i = 0; i < middle; i++) {
            ady[us[i]].push_back(vs[i]);
            ady[vs[i]].push_back(us[i]);
        }

        if (isBipartite())
            left = middle + 1;
        else
            right = middle;
    }

    cout << right << endl;


    return 0;
}