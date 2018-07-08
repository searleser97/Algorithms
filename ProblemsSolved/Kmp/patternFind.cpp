#include <bits/stdc++.h>

using namespace std;

// f = error function
// cf = create error function
// p = pattern
// t = text
// pos = positions where pattern is found in text

int MAXN = 1000000;
vector<int> f(MAXN + 1);

vector<int> kmp(string &p, string &t, int cf) {
  vector<int> pos;
  if (cf) f[0] = -1;
  for (int i = cf, j = 0; j < t.size();) {
    while (i > -1 && p[i] != t[j]) i = f[i];
    i++, j++;
    if (cf) f[j] = i;
    if (!cf && i == p.size()) pos.push_back(j - i), i = f[i];
  }
  return pos;
}

vector<int> search(string &p, string &t) {
  kmp(p, p, -1); // create error function
  return kmp(p, t, 0); // search in text
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str, pattern;
        cin >> str >> pattern;
        vector<int> positions = search(pattern, str);
        if (positions.size() == 0) {
            cout << "Not Found" << "\n\n";
            continue;
        }
        cout << positions.size() << '\n';
        for (int j = 0; j < positions.size(); j++) {
            cout << positions[j] + 1 << " ";
        }
        cout << "\n\n";
    }
    return 0;
}