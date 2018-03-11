#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<int> > mySieve(int N) {
    int n = N + 1;
    vector<int> dic(n);
    vector<int> primes = {2, 3};
    dic[0] = -1;
    dic[1] = 1;
    for (int i = 4; i < n; i += 2)
        dic[i] = 2;
    for (int i = 9; i < n; i += 3)
        dic[i] = 3;
    int i = 5, w = 2, k = i * i;
    while (k < n) {
        if (dic[i] == 0) {
            primes.push_back(i);
            // skip multiples of 2
            int jump = 2 * i;
            for (int j = k; j < n; j += jump)
                dic[j] = i;
        }
        i += w;
        w = 6 - w;
        k = i * i;
    }
    // if you need primes bigger than the root of N
    while (i < n) {
        if (dic[i] == 0)
            primes.push_back(i);
        i += w;
        w = 6 - w;
    }
    return {dic, primes};
}

bool isPrime(long long int N, vector<int> &sieve, vector<int> &primes) {
    if (N < sieve.size())
        return sieve[N] == 0 ? true : false;
    for (int prime : primes) {
        if (prime * prime > N)
            break;
        if (N % prime == 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    pair<vector<int>, vector<int> > sieve = mySieve(63246);
    int t;
    long long int n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;

        if (n < 3LL)
            cout << 2;
        else {
            if ((n & 1LL) == 0)
                n += 1LL;
            for (long long int l = n; l < 5000000000LL; l += 2LL) {
                if (isPrime(l, sieve.first, sieve.second)) {
                    cout << l;
                    break;
                }
            }
        }

        if (i != t - 1)
            cout << "\n";
    }
    return 0;
}