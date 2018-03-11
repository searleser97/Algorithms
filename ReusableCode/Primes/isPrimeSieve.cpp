#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<int> > mySieve(int N) {
    int n = N + 1;
    vector<int> dic(n);
    vector<int> primes;
    if (N == 2)
        primes = {2};
    if (N > 2)
        primes = {2, 3};
    dic[0] = -1;
    dic[1] = 1;
    for (int i = 4; i < n; i += 2)
        dic[i] = 2;
    for (int i = 9; i < n; i += 6)
        dic[i] = 3;
    int i = 5, w = 2, k = i * i;
    while (k < n) {
        if (dic[i] == 0) {
            primes.push_back(i);
            // skip multiples of 2
            int jump = 2 * i;
            for (long long int j = k; j < n; j += jump)
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

bool isPrime(int N, vector<int> &sieve, vector<int> &primes) {
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
    pair<vector<int>, vector<int> > sieve = mySieve(10000000);
    long long int n;
    cin >> n;
    cout << isPrime(n, sieve.first, sieve.second) << '\n';
    return 0;
}
