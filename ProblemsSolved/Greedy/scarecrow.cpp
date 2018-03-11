#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        int nScareCrows = 0;
        bool prevIsFertile = false;
        bool prevIsCovered = false;
        bool ignore = false;
        cin >> N;
        while (N--) {
            char land;
            cin >> land;
            if (ignore) {
                ignore = false;
                continue;
            }
            if (prevIsFertile && !prevIsCovered) {
                nScareCrows++;
                prevIsCovered = true;
                prevIsFertile = true;
                ignore = true;
            }
            else if (land == '#' && N > 0) {
                N--;
                cin >> land;
                if (land == '.' && N == 0)
                    nScareCrows++;
                prevIsFertile = land == '.' ? true : false;
                prevIsCovered = false;

            }
            else if (land == '.') {
                prevIsFertile = true;
                prevIsCovered = false;
                if (N == 0)
                    nScareCrows++;
            }
        }
        cout << "Case " << i << ": " << nScareCrows << endl;
    }
    return 0;
}