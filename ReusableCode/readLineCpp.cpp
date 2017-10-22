#include <bits/stdc++.h>

using namespace std;
/*
string strInput() {
    string ans;
    cin >> ans;
    cin.ignore();
    return ans;
}

int intInput() {
    int ans;
    cin >> ans;
    cin.ignore();
    return ans;
}

double dInput() {
    double ans;
    cin >> ans;
    cin.ignore();
    return ans;
}
*/
string input() {
    string ans;
    cin >> ws;
    getline(cin, ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    string ans;
    // cout << strInput() << endl;
    cin >> ans;
    cout << ans << endl;
    cout << input() << endl;
    return 0;
}
