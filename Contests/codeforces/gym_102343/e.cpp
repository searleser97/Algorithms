#include <bits/stdc++.h>
using namespace std;

vector<int> sieve;

void primeSieve(int n) {
    sieve.assign(n + 1, 0);
    for (int i = 3; i * i <= n; i += 2)
        if (!sieve[i])
            for (int j = i * i; j <= n; j += 2 * i)
                if (!sieve[j]) sieve[j] = i;
}

int main() {
    int n, k;
    cin >> n >> k;
    primeSieve(1e7);
    int count = 0, ans = -1;
    for (int i = 1; i < 1e7; i++) {
        if (!sieve[i] && (i & 1) || i == 2) continue;
        if (sieve[i] > n || ((~i & 1) && n < 2)) count++;
        if (count == k) { ans = i; break; }
    }
    cout << ans << endl; 
    return 0;
}
