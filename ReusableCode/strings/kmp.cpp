#include <bits/stdc++.h>

using namespace std;

vector<int> prefixArray(string& pattern) {

    vector<int> prefixArr(pattern.size());
    for (int i = 0, j = 1; j < pattern.size();)
    {
        if (pattern[i] == pattern[j])
        {
            prefixArr[j] = i + 1;
            i++;
            j++;
        } else {
            if (i != 0)
                i = prefixArr[i - 1];
            else {
                prefixArr[j] = 0;
                j++;
            }
        }
    }
    return prefixArr;
}

vector<int> kmp(string& str, string& pattern) {
    vector<int> positions;
    if (pattern.size() == 0)
        return positions;
    vector<int> prefixArr = prefixArray(pattern);
    for (int i = 0, j = 0; j < str.size();) {
        if (pattern[i] == str[j]) {
            j++;
            i++;
        } else {
            if (i != 0) {
                i = prefixArr[i - 1];
            } else {
                j++;
            }
        }
        if (i == pattern.size()) {
            positions.push_back(j + 1 - pattern.size());
            i = prefixArr[i - 1];
        }
    }
    return positions;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        int q;
        cin >> q;
        for (int j = 0; j < q; j++) {
            string pattern;
            cin >> pattern;
            vector<int> positions = kmp(str, pattern);
            if (positions.size() == 0)
                cout << "not found" << endl;
            else {
                cout << "found at:";
                for (auto position : positions)
                    cout << " " << position;
                cout << endl;
            }
        }

    }
    return 0;
}
