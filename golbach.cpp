#include <bits/stdc++.h>

using namespace std;

pair<vector<bool> , vector<int>> primos(int N) {
    vector<bool> arr(N + 1);
    vector<int> primos = {2, 3};
    arr[2] = true;
    arr[3] = true;

    int i = 5;
    int w = 2;
    while(i <= N) {
        arr[i] = true;
        i += w;
        w = 6 - w;
    }

    i = 5;
    w = 2;
    int h = 0;
    while (i * i <= N) {
        if (arr[i]) {
            h = 5;
            while(i * h <= N) {
                arr[i * h] = false;
                h += 1;
            }
        }
        i += w;
        w = 6 - w;
    }
    i = 5;
    w = 2;
    while(i <= N) {
        if(arr[i]) {
            primos.push_back(i);
        }
        i += w;
        w = 6 - w;
    }
    return {arr, primos};
}

void printv(std::vector<int> v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << "," << v[i];
    cout << "]" << endl;
}

void printv(std::vector<bool> v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << "," << v[i];
    cout << "]" << endl;
}

int main() {
    pair<vector<bool>, vector<int>> p = primos(1000000);
    vector<bool> criba = p.first;
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        bool flag = false;
        int a = 1;
        int b = n - 1;
        while (a <= b) {
            if (criba[a] && criba[b]) {
                flag = true;
                break;
            }
            else {
                a++;
                b--;
            }
        }

        if (flag)
            cout << to_string(n) + " = " + to_string(a) + " + " + to_string(b) << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}
