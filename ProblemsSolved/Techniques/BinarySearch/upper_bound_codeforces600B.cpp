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
}  // be aware that r can be < given l and l > given r

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    while (n--) cin >> v[v.size() - n - 1];
    sort(v.begin(), v.end());
    while (m--) {
        int e;
        cin >> e;
        vector<int> ans = bSearch(v, e, 0, v.size() - 1);
        cout << ans[1];
        if (m) cout << " ";
    }
    cout << endl;
    return 0;
}
