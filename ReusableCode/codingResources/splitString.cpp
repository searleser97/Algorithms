#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char token) {
    stringstream test(str);
    string segment;
    vector<std::string> seglist;

    while (std::getline(test, segment, token))
        seglist.push_back(segment);
    return seglist;
}

int main () {
    string str;
    getline(cin, str);
    vector<string> segments = split(str, ' ');
    for (string segment : segments)
        cout << segment << endl;
    return 0;
}