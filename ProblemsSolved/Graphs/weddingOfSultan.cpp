#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        map<char, int> node;
        unordered_map<int, int> parent;
        string trail;
        cin >> trail;
        int current = trail[0];
        node[current] = 0;
        parent[current] = current;

        for (int i = 1; i < trail.size(); i++) {
            if (current == trail[i]) {
                current = parent[trail[i]];
                if (current != trail[i])
                    node[current] += 1;
            } else {
                parent[trail[i]] = current;
                current = trail[i];
                node[trail[i]] += 1;
            }

        }
        cout << "Case " << t << endl;
        for (auto i : node) {
            cout << i.first << " = " << i.second << endl;
        }
    }
}