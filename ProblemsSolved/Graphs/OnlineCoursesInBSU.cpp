#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ady;
vector<int> vis;
vector<int> toposorted;
int n, k;

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

int main() {
    cin >> n >> k;
    ady.resize(n + 1);
    vis.resize(n + 1);
    vector<int> mainCourses(k);
    for (int i = 0; i < k; i++)
        cin >> mainCourses[i];
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int v;
            cin >> v;
            ady[i].push_back(v);
        }
    }
    for (auto &mainCourse : mainCourses)
        if (!vis[mainCourse])
            if (!toposort(mainCourse)){
                cout << "-1" << endl;
                return 0;
            }
    cout << toposorted.size() << endl;
    cout << toposorted[0];
    for (int i = 1; i < toposorted.size(); i++)
        cout << " " << toposorted[i];
    cout << endl;

    return 0;
}