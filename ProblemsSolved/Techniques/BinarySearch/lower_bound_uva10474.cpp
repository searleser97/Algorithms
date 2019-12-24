#include <bits/stdc++.h>

using namespace std;

typedef int T;

vector<int> bSearch(vector<T> &v, T e, int l, int r,
                    bool lower = 0, bool inv = 0) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (e < v[mid])
      inv ? l = mid + 1 : r = mid - 1;
    else if (e > v[mid])
      inv ? r = mid - 1 : l = mid + 1;
    else
      lower ? r = mid - 1 : l = mid + 1;
  }
  return {r, l};
}

int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 0, nq = 0, q = 0;
    for (int l = 1; true; l++) {
        cin >> n >> nq;
        if (!n & !nq)
            return 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        cout << "CASE# " << l << ":" << endl;
        for (int i = 0; i < nq; i++) {
            cin >> q;
            int pos = bSearch(v, q, 0, v.size() - 1, true)[1];
            if (v[pos] == q)
                cout << q << " found at " << pos + 1 << endl;
            else
                cout << q << " not found" << endl;
        }
    }
    return 0;
}