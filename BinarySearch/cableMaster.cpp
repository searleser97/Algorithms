#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


void binaria(vector<double> &cables, int requestedPieces, double max) {
    double left = 0, right = max;
    int k = 0;
    while (k < 25) {
        double middle = (left + right) / 2.0;
        int myRequestedPieces = 0;
        for (int i = 0; i < cables.size(); i++) {
            myRequestedPieces += (int)(cables[i] / middle);
        }

        if (myRequestedPieces < requestedPieces)
            right = middle;
        else
            left = middle;
        k++;
    }
    cout << setprecision(2) << fixed << floor(right * 100.0) / 100.0 << endl;
}


int main() {
    int n, k;

    cin >> n >> k;
    vector<double> cables(n);
    for (int i = 0; i < n; i++) {
        cin >> cables[i];
    }

    binaria(cables, k, 100000);
    return 0;
}
