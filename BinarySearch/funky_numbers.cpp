#include <bits/stdc++.h>
using namespace std;


void printv(vector<int>& v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        cout << "," << v[i];
    }
    cout << "]" << endl;

}

int binaria(vector<int>& v, int n) {
    int start = 0, end = v.size() - 1, middle = 0;
    while(start <= end) {
        middle = (start + end) / 2;
        if (v[middle] == n)
            return 1;
        if (n < v[middle])
            end = middle - 1;
        else
            start = middle + 1;
    }
    return 0;
}

int main () {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0, k = 1; true; i++, k++) {
        int aux = (k * (k + 1)) / 2;
        if (aux >= n)
            break;
        v.push_back(aux);
    }
    for (int i = 0; i < v.size(); i++) {
        if(binaria(v, n - v[i])) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}