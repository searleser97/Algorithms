#include <bits/stdc++.h>

using namespace std;

vector<bool> primos(int N) {
    vector<bool> arr(N + 1);
    arr[2] = true;
    arr[3] = true;

    int i = 5;
    int w = 2;
    while (i <= N) {
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
            while (i * h <= N) {
                arr[i * h] = false;
                h += 1;
            }
        }
        i += w;
        w = 6 - w;
    }
    return arr;
}

void printv(std::vector<bool> v) {
    cout << "[";
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << "," << v[i];
    cout << "]" << endl;
}

int main() {
    vector<bool> cribaPrimos = primos(100000);
    while (true) {
        string str;
        int prime = 0;
        cin >> str;
        if (str == "0")
            break;
        int i = 0;
        while (i < str.size()) {
            for (int l = 1; l < 6; l++) {
                if (i + l > str.size())
                    continue;
                int actPosiblePrime = stoi(str.substr(i, l));
                if (cribaPrimos[actPosiblePrime]) {
                    if (prime < actPosiblePrime)
                        prime = actPosiblePrime;
                }
            }
            i++;
        }
        cout << prime << endl;
    }
    return 0;
}