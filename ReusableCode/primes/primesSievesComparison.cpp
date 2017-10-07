#include <bits/stdc++.h>

using namespace std;


vector<long long int> sieve(long long int N) {
    long long int n = N + 1LL;
    vector<long long int> dic(n);
    dic[0] = -1LL;
    dic[1] = 1LL;
    for (long long int i = 4LL; i < n; i += 2LL)
        dic[i] = 2LL;
    for (long long int i = 9LL; i < n; i += 3LL)
        dic[i] = 3LL;
    long long int i = 5LL, w = 2LL, k = i * i;
    while (k < n) {
        if (dic[i] == 0LL)
            for (long long int j = k; j < n; j += i)
                dic[j] = i;
        i += w;
        w = 6LL - w;
        k = i * i;
    }
    return dic;
}

// Criba de Eratostenes de 1 a n.
vector<long long int> clasicSieve(long long int n) {
    vector<long long int> criba(n + 1LL);
    for (long long int i = 4LL; i <= n; i += 2LL)
        criba[i] = 2LL;
    for (long long int i = 3LL; i * i <= n; i += 2LL)
        if (!criba[i])
            for (long long int j = i * i; j <= n; j += i)
                if (!criba[j]) criba[j] = i;
    return criba;
}


int main() {
    long long int n = 10000000LL;
    cin >> n;
    clock_t start, stop;
    for (int i = 0; i < 4; i++) {
        start = clock();
        clasicSieve(n);
        stop = clock();
        cout << (double)(stop - start) / CLOCKS_PER_SEC << " seconds." << endl;

        start = clock();
        sieve(n);
        stop = clock();
        cout << (double)(stop - start) / CLOCKS_PER_SEC << " seconds." << endl;
    }
    return 0;
}
