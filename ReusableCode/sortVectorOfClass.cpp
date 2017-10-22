#include <bits/stdc++.h>

using namespace std;

struct Object {
    char first;
    int second;
};

void printv(vector<Object> v) {
    if (v.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[{" << v[0].first << ", " << v[0].second << "}";
    for (int i = 1; i < v.size(); i++) {
        cout << ", {" << v[i].first << ", " << v[i].second << "}";
    }
    cout << "]" << endl;
}

int main() {
    vector<Object> v = {{'c',3}, {'a', 1}, {'b', 2}};
    sort(v.begin(), v.end(), [](Object a, Object b) {
        return a.first < b.first;
    });
    printv(v);
    return 0;
}