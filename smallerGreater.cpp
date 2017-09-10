#include <bits/stdc++.h>
typedef long long int lli;

using namespace std;

bool isBitSet(lli n, lli pos) {
    return (n >> pos) & 1LL;
}

void setBit(lli &n, lli pos) {
    n |= 1LL << pos;
}
void unSetBit(lli &n, lli pos) {
    n &= ~(1LL << pos);
}

lli initializeBitsWindow(lli n, lli k) {
    lli aux = (1LL << k) - 1LL;
    return n | aux;
}

void slideWindow(lli &n, lli k, lli pos) {
    unSetBit(n, pos);
    setBit(n, pos + k);
}

lli bitsInInt(lli n) {
    return floor(log2(n) + 1LL);
}

int main() {
    lli m, k, mcopy;
    while (cin >> m >> k) {
        mcopy = initializeBitsWindow(m, k);
        lli intSizeInBits = bitsInInt(m);
        lli limit = intSizeInBits - k;
        if (limit < 1LL) {
            cout << (1LL << k) - 1LL << endl;
            continue;
        }
        lli consecutiveSetBits = 0;
        vector<lli> v(limit);
        lli i = 0;
        bool flag = false;
        for (; i < limit; i++) {
            if (isBitSet(m, i)) {
                consecutiveSetBits++;
            } else {
                consecutiveSetBits = 0;
            }
            if (consecutiveSetBits == k) {
                cout << m << endl;
                flag = true;
                break;
            }
            v[i] = mcopy;
            slideWindow(mcopy, k, i);
        }
        if (flag)
            continue;
        limit = limit + k;
        for (; i < limit; i++) {
            if (isBitSet(m, i)) {
                consecutiveSetBits++;
            } else {
                consecutiveSetBits = 0;
            }
            if (consecutiveSetBits == k) {
                cout << m << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        v[intSizeInBits - k - 1LL] = mcopy;
        auto min_value = *std::min_element(v.begin(),v.end());
        if (min_value > m)
            cout << min_value << endl;
        else
            cout << m << endl;
    }
    return 0;
}