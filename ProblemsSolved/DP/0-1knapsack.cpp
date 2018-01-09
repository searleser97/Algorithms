// uva - 10130 SuperSale
#include <bits/stdc++.h>
using namespace std;
typedef int T;

vector<vector<T>> knapsack(vector<T> &val, vector<T> &weight, T totalWeight) {
    vector<vector<T>> dpMat(val.size() + 1, vector<T>(totalWeight + 1));
    for (int i = 1; i <= val.size(); i++) {
        for (int currTW = 1; currTW <= totalWeight; currTW++) {
            if (currTW == 0)
                continue;
            if (weight[i - 1] > currTW)
                dpMat[i][currTW] = dpMat[i - 1][currTW];
            else
                dpMat[i][currTW] = max(dpMat[i - 1][currTW], val[i - 1] + dpMat[i - 1][currTW - weight[i - 1]]);
        }
    }
    return dpMat;
}

int main() {
    int nT;
    cin >> nT;
    while (nT--) {
        int n;
        cin >> n;
        vector<T> val(n), weight(n);
        for (int i = 0; i < n; i++)
            cin >> val[i] >> weight[i];
        int G;
        cin >> G;
        T maxWeight = 0;
        vector<T> persons(G);
        for (int i = 0; i < G; i++) {
            T aux;
            cin >> aux;
            maxWeight = max(maxWeight, aux);
            persons[i] = aux;
        }
        vector<vector<T>> dpMat = knapsack(val, weight, maxWeight);
        int ans = 0;
        int lastRow = dpMat.size() - 1;
        for (auto weight : persons) {
            ans += dpMat[lastRow][weight];
        }
        cout << ans << endl;
    }

    return 0;
}