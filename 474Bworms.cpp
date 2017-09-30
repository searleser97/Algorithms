#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m, q, lr = 1, rr, wormsInPile, left, right, mid;
    cin >> n;
    vector<pair<long long int, long long int> > a(n);

    for (int i = 0; i < n; i++) {
        cin >> wormsInPile;
        rr = lr + wormsInPile;
        a[i] = {lr, rr - 1};
        lr = rr;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> q;
        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (q < a[mid].first)
                right = mid - 1;
            else if (q > a[mid].second)
                left = mid + 1;
            else {
                cout << mid + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
