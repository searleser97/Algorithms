#include <bits/stdc++.h>
using namespace std;


void printv(vector<int>& v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        cout << "," << v[i];
    }
    cout << "]" << endl;

}

int main () {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    int N, S;
    
    while (cin >> N >> S) {
        vector<int> v(N);
        int suma = 0, ini = 0;
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < N; i++) {
            suma += v[i];
            while (suma > S) {
                suma -= v[ini];
                ini++;
            }
            if (suma == S) {
                cout << ini + 1 << " " << i + 1 << endl;
                break;
            }
            if (i == N - 1)
                cout << "-1" << endl;
        }
        
    }
    return 0;
}