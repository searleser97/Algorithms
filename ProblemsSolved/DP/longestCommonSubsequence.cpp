// uva - 10130 SuperSale
#include <bits/stdc++.h>
using namespace std;
typedef int T;

vector<vector<int>> lcs(string str1, string str2) {
    vector<vector<int>> lcsMat(str1.size() + 1, vector<int>(str2.size() + 1));
    for (int i = 1; i < lcsMat.size(); i++) {
        for (int j = 1; j < lcsMat[i].size(); j++) {
            if (str1[i - 1] == str2[j - 1])
                lcsMat[i][j] = 1 + lcsMat[i - 1][j - 1];
            else
                lcsMat[i][j] = max(lcsMat[i][j - 1], lcsMat[i - 1][j]);
        }
    }
    return lcsMat;
}

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
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> lcslocal = lcs(str1, str2);
    for (auto i : lcslocal)
        printv(i);
}
