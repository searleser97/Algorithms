#include <bits/stdc++.h>


using namespace std;

long long int mod = 10000007LL;

long long int Exponenciar(long long int a, long long int n, long long int m) {
    long long int resultado = 1LL;
    for (; n; n >>= 1LL) {
        if (n & 1LL)
            resultado = (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}

int main() {

    long long int n, k;
    while (cin >> n >> k) {
        if (n == 0LL && k == 0LL)
            break;
        long long int ans;
        ans = (Exponenciar(n, k, mod) + Exponenciar(n, n, mod)) % mod;
        ans = (ans + ((2 * (Exponenciar(n - 1, k, mod) + Exponenciar(n - 1, n - 1, mod)) % mod) % mod)) % mod;
        cout << ans << endl;
    }
}
