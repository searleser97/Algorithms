#include<bits/stdc++.h>

using namespace std;

void _main(int T) {
    int n, k;
    unordered_map<int, bool> um;

    cin >> n >> k;
    int x, y, xans = 1000000, yans;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        
        cin >> x;
        if (x == 0)
            continue;
        int y = k / x;
        if (k % x == 0 and um.count(y)) {
            x = min(x, y);
            y = k / x;
            if (x < xans) {
                xans = x;
                yans = y;
                flag = true;
            }
        }
        um[x] = true;
    }

    if (flag)
        cout << xans << " " << yans << endl;
    else
        cout << -1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        _main(i);
    return 0;
}