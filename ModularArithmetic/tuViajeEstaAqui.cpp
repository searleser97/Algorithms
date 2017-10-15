#include <bits/stdc++.h>


using namespace std;


int main() {
    string s, s2;
    cin >> s >> s2;
    int ans = 1, ans2 = 1;
    for (int i = 0; i < s.size(); i++) {
        ans *= (s[i] - 'A' + 1);
        ans = ans % 47;
    }

    for (int i = 0; i < s2.size(); i++) {
        ans2 *= (s2[i] - 'A' + 1);
        ans2 = ans2 % 47;
    }

    if (ans == ans2)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;

    return 0;
}