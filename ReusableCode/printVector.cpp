#include <bits/stdc++.h>

using namespace std;

void printv(vector<int> v) {
    if (v.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << ", " << v[i];
    }
    cout << "]" << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    printv(v);
    return 0;
}