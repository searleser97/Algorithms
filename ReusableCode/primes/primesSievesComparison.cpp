#include <bits/stdc++.h>

using namespace std;


vector<int> sieve(int N) {
    int n = N + 1;
    vector<int> dic(n);
    dic[0] = -1;
    dic[1] = 1;
    for (int i = 4; i < n; i += 2)
        dic[i] = 2;
    for (int i = 9; i < n; i += 3)
        dic[i] = 3;
    int i = 5, w = 2, k = i * i;
    while (k < n) {
        if (dic[i] == 0) {
            int jump = 2 * i;
            for (int j = k; j < n; j += jump)
                dic[j] = i;
        }
        i += w;
        w = 6 - w;
        k = i * i;
    }
    return dic;
}

// Criba de Eratostenes de 1 a n.
vector<int> clasicSieve(int n) {
    vector<int> criba(n + 1);
    for (int i = 4; i <= n; i += 2)
        criba[i] = 2;
    for (int i = 3; i * i <= n; i += 2)
        if (!criba[i])
            for (int j = i * i; j <= n; j += i)
                if (!criba[j]) criba[j] = i;
    return criba;
}


int main() {
    int n = 10000000;
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
