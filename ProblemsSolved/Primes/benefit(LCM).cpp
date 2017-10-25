#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, c;
        cin >> a >> c;

        if (c % a != 0) {
            cout << "NO SOLUTION" << endl;
            continue;
        }

        int b = c / a;
        for (int i = b; i <= c; i += b) {

        }
    }

}