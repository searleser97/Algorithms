#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> &v, int &n) {
    int middle = 0;
    int start = 0;
    int end = v.size() - 1;
    int posFound = -1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (v[middle] == n) {
            posFound = middle;
            end = middle - 1;
        }
        if (v[middle] < n)
            start = middle + 1;
        if (v[middle] > n)
            end = middle - 1;
    }
    return posFound;
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 0, nq = 0, q = 0;
    for (int l = 1; true; l++) {
        cin >> n >> nq;
        if (!n & !nq)
            return 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        cout << "CASE# " << l << ":" << endl;
        for (int i = 0; i < nq; i++) {
            cin >> q;
            int pos = binSearch(v, q);
            if (pos != -1)
                cout << q << " found at " << pos + 1 << endl;
            else
                cout << q << " not found" << endl;
        }
    }
    return 0;
}