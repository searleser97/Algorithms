#include <bits/stdc++.h>

using namespace std;

long long int binaria(int n, long long int m, vector<long long int>& desksTime) {
    long long int max = 1LL << 60;
    long long int l = 1LL;
    long long int r = max;
    long long int mid = 0;

    while (l <= r) {
        mid = (l + r) / 2LL;
        long long int people = 0LL;

        for (int i = 0; i < n; i++)
            people += mid / desksTime[i];

        if (people < m) {
            l = mid + 1LL;
        }
        else
            r = mid - 1LL;
    }

    return l;
}

int main() {
    int n;
    long long int m;
    cin >> n >> m;
    vector<long long int> desksTime(n);
    for (int i = 0; i < n; i++) {
        cin >> desksTime[i];
    }
    cout << binaria(n, m, desksTime) << endl;
    return 0;
}
