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

vector<int> getSequence(vector<vector<T>> lcsMat) {

}

int main() {
    string str1, str2;
    while (getline(cin, str1)) {
        getline(cin, str2);
        vector<vector<int>> lcslocal = lcs(str1, str2);
        cout << lcslocal[lcslocal.size() - 1][lcslocal[0].size() - 1] << endl;
    }
}
