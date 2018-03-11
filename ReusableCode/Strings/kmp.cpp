#include <bits/stdc++.h>

using namespace std;

vector<int> prefixArray(string& pattern) {

    vector<int> prefixArr(pattern.size());
    for (int i = 0, j = 1; j < pattern.size();)
    {
        if (pattern[i] == pattern[j])
        {
            i++;
            prefixArr[j] = i;
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
        string str, pattern;
        cin >> str >> pattern;
        vector<int> positions = kmp(str, pattern);
        if (positions.size() == 0) {
            cout << "Not Found" << "\n\n";
            continue;
        }
        cout << positions.size() << '\n';
        for (int j = 0; j < positions.size(); j++) {
            cout << positions[j] << " ";
        }
        cout << "\n\n";
    }
    return 0;
}
