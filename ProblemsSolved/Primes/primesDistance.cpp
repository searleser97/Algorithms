#include <bits/stdc++.h>

using namespace std;


void printv(std::vector<int> v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << "," << v[i];
    cout << "]" << endl;
}

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
    while(i < n) {
        if (dic[i] == 0)
            primes.push_back(i);
        i += w;
        w = 6 - w;
    }
    return {dic, primes};
}

bool is_prime(int N, vector<int> &sieve, vector<int> &primes) {
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

struct nearestPrimes {
    long long int left;
    long long int right;
};

struct furthestPrimes {
    long long int left;
    long long int right;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pair<vector<int>, vector<int> > sievePrimes = mySieve(50000);
    vector<int> s = sievePrimes.first;
    vector<int> primes = sievePrimes.second;
    long long int L;
    long long int U;
    long long int left;
    long long int right;
    long long int minimum;
    long long int maximum;

    while (cin >> L >> U) {
        if (L == U || U == 2LL) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }
        minimum = 1000001LL;
        maximum = 0LL;
        left = L;
        nearestPrimes NearestPrimes;
        furthestPrimes FurthestPrimes;
        if (left <= 2LL) {
            NearestPrimes = {2LL, 3LL};
            FurthestPrimes = {2LL, 3LL};
            minimum = 1LL;
            maximum = 1LL;
        }

        if ((left & 1LL) == 0)
            left += 1LL;

        while (true) {
            if (is_prime(left, s, primes))
                break;
            left += 2LL;
        }

        right = left + 2LL;
        while (right <= U) {
            if (is_prime(right, s, primes)) {
                long long int distance = right - left;
                if (distance < minimum) {
                    NearestPrimes = {left, right};
                    minimum = distance;
                }
                if (distance > maximum) {
                    FurthestPrimes = {left, right};
                    maximum = distance;
                }
                left = right;
            }
            right += 2LL;
        }

        if (maximum == 0LL) {
            cout << "There are no adjacent primes." << endl;
        } else
            cout << NearestPrimes.left << "," << NearestPrimes.right << " are closest, " << FurthestPrimes.left << "," << FurthestPrimes.right << " are most distant." << endl;
    }



}
