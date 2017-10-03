#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) {
    return (int) c - '0';
}

int main() {
    string a, b;
    while (true) {
        cin >> a >> b;
        if (a == "0" && b == "0")
            break;
        string bigger, smaller;
        if (a.size() > b.size()) {
            bigger = a;
            smaller = b;
        } else {
            bigger = b;
            smaller = a;
        }
        int count = 0;
        int carry = 0;
        int i = bigger.size() - 1;
        for (int j = smaller.size() - 1;  j > -1; i--, j--) {
            if (charToInt(bigger[i]) + charToInt(smaller[j]) + carry > 9)
                count++, carry = 1;
            else
                carry = 0;
        }

        for (; i > -1; i--) {
            if (charToInt(bigger[i]) + carry > 9)
                count++, carry = 1;
            else
                carry = 0;
        }

        if (count == 0) {
            cout << "No carry operation." << endl;
        } else if (count == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }
    }

    return 0;
}
