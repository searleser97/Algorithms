#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> ar(10);
  // copy(arr.begin(), arr.end(), ar.begin() + 5);
  for (auto &i : ar)
    cout << i << " ";
  cout << endl;
  return 0;
}