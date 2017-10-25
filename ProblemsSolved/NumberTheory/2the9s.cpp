#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string n;
        cin >> n;
        if (n == "0")
            break;
        string naux = n;
        int depth = 1, sum;
        while (true) {
            sum = 0;
            for (int i = 0; i < n.size(); i++) {
                sum += n[i] - '0';
            }
            n = to_string(sum);
            if (n.size() == 1)
                break;
            depth++;
        }
        if (sum % 9 == 0)
            cout << naux << " is a multiple of 9 and has 9-degree " << depth << ".\n";
        else
            cout << naux << " is not a multiple of 9.\n";
    }
    return 0;
}
