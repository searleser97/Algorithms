
 #include<bits/stdc++.h>

using namespace std;

void _main(int T) {
    int n, m;
    map<int, int> ages, packets;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        ages[aux] += 1;
    }
    for (int i = 0; i < m; i++) {
        int aux;
        cin >> aux;
        packets[aux] += 1;
    }

    vector<pair<int, int>> vp;
    for (auto i : packets) {
        // cout << i.first << " " << i.second << endl;
        vp.push_back({i.first, i.second});
    }

    if (ages.size() > packets.size()) {
        cout << "NO" << endl;
        return;
    }

    int l = 0;
    bool flag = true;
    for (auto i : ages) {
        while (true) {
            if (l >= vp.size()) {
                cout << "NO" << endl;
                return;
            }
            if (i.second > vp[l].second) {
                flag = false;
                l++;
            } else {
                flag = true;
                break;
            }
        }
        l++;
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        _main(i);
    return 0;
}