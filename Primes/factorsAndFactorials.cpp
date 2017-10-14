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
    for (int i = 9; i < n; i += 3)
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

void printv(vector<int> v) {
    if (v.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << ", " << v[i];
    }
    cout << "]" << endl;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> primes = mySieve(n).second;
        int factorsSize = primes.size();
        vector<int> factorsCount(factorsSize);
        int primeToAPower;
        int i = 0;
        for (int prime : primes) {
            primeToAPower = prime;
            // number of numbers divided by 'K' in a range 1...N = N / K
            int div = n / primeToAPower;
            while (true) {
                factorsCount[i] += div;
                primeToAPower *= prime;
                div = n / primeToAPower;
                if (div == 0)
                    break;
            }
            i++;
        }

        // output format
        cout << setw(3) << n << "! =";
        for (int i = 0; i < factorsSize; i++) {
            if (i == 15)
                cout << "\n      ";
            cout << setw(3) << factorsCount[i];
        }
        cout << endl;
    }
    return 0;
}
