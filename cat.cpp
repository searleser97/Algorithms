#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, b;
    while(cin >> N >> b) {
        int pot = 1 << N;
        float pos = pot - b;
        string ans;

        while (pos > 1) {
            if (floor(pos / 2) == pos / 2)
                ans += "L";
            else
                ans += "R";
            pos = floor(pos / 2);
        }
        cout << "Instructions: ";
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i];
        ans = "";
        cout << endl;
    }

    return 0;
}