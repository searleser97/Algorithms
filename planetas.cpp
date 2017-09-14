#include <bits/stdc++.h>
using namespace std;

double suma1(double x, vector<int> &planetas) {
    double suma = 0;
    for (int i = 0; i < planetas.size(); i++) {
        suma += 1 / (planetas[i] - x);
    }
    return suma;
}

double binaria(double ini, double fin, vector<int> &planetas) {
    double middle = 0;
    for (int i = 0; i < 25; i++) {
        middle = (ini + fin) / 2;
        double suma  = suma1(middle, planetas);
        if (suma < 0) {
            ini = middle;
        }
        if (suma > 0) {
            fin = middle;
        }
    }
    return middle;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;

    cin >> n;
    vector<int> planetas(n);
    for (int i = 0; i < n; i++) {
        cin >> planetas[i];
    }
    sort(planetas.begin(), planetas.end());
    cout << n - 1 << endl;
    for (int i = 1; i < planetas.size(); i++) {
        cout << fixed << setprecision(3) << fixed << binaria(planetas[i - 1], planetas[i], planetas) << " ";
    }
    cout << endl;
    return 0;
}
