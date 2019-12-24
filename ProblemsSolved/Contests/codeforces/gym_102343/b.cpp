#include <bits/stdc++.h>
using namespace std;



int main() {
    string str;
    cin >> str;
    vector<pair<int, char>> v(26);
    for (char &c : str) {
        v[c - 'a'].first++;
        v[c - 'a'].second = c;
    }

    auto cmp = [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first < b.first) return false;
        else if (a.first > b.first) return true;
        else return a.second < b.second;
    };
    sort(v.begin(), v.end(), cmp);
    for (auto &p : v) {
        for (int i = 0; i < p.first; i++) {
            cout << p.second;
        }
    }
    cout << endl;
    return 0;
}
