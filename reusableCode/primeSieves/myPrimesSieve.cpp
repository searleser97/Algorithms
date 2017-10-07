#include <bits/stdc++.h>

using namespace std;

// sieve of primes, use unordered_map if you want to save memory
// however using it will make this slower
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
        if (dic[i] == 0)
            for (long long int j = k; j < n; j += i)
                dic[j] = i;
        i += w;
        w = 6 - w;
        k = i * i;
    }
    return dic;
}


vector<int> primesToN(int N) {
    vector<int> s = sieve(N);
    vector<int> primes;
    for (int i = 0; i < s.size(); i++)
        if (!s[i])
            primes.push_back(i);
    return primes;
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
    int n;
    cin >> n;
    printv(primesToN(n));
}
