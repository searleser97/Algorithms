#include <bits/stdc++.h>

using namespace std;


// gcd(a, b) = ax + by
vector<long long int> extendedGCD(long long int a, long long int b) {
    if (a > 0LL && b == 0LL) {
        return {a, 1LL, 0LL};
    }
    long long int x = 1LL, y = 0LL, prevx = 0LL, prevy = 1LL, q, remainder;
    while (true) {
        q = a / b;
        remainder = a - b * q;
        if (remainder == 0LL)
            break;
        a = b;
        b = remainder;
        x = x - prevx * q;
        swap(x, prevx);
        y = y - prevy * q;
        swap(y, prevy);
    }
    // gcd = b, x = prevx, y = prevy
    return {b, prevx, prevy};
}


int main() {
    long long int a, b;
    while (cin >> a >> b) {
        vector<long long int> ans = extendedGCD(a, b);
        cout << ans[1] << " " << ans[2] << " " << ans[0] << "\n";
    }
    
    return 0;
}
