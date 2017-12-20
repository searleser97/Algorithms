#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcdI(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    cout << gcdI(a, b) << "\n";
}
