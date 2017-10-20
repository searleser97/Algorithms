#include <bits/stdc++.h>
using namespace std;
double p, q, r , s , t, u;

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 1e-9 || p + r + u < 0) {
            cout << "No solution" << endl;
            continue;
        }
        double start = 0, end = 1, x = 0, ansEq;
        for (int i = 0; i < 30; i++) {
            x = (start + end) / 2;
            ansEq = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
            if (ansEq > 0)
                start  = x;
            else
                end = x;
        }
        cout << setprecision(4) << fixed << x << endl;
    }
    return 0;
}