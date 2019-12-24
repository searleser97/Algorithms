// 13
#include <bits/stdc++.h>
using namespace std;

struct SuffixAutomaton {
  vector<int> len, link;
  vector<map<char, int>> next;
  int size, last;
  // 4
  void init(int n) {
    len = link = vector<int>(2 * n);
    next.resize(2 * n);
  }
  // 6
  // O(N)
  SuffixAutomaton(const string& s) {
    init(s.size());
    len[0] = 0, link[0] = -1, size = 1, last = 0;
    for (const auto& c : s) add(c);
  }
  // 21
  // O(1)
  void add(const char& c) {
    int p = last, cur = size++;
    len[cur] = len[p] + 1;
    while (p != -1 && !next[p].count(c))
      next[p][c] = cur, p = link[p];
    if (p == -1) link[cur] = 0;
    else {
      int q = next[p][c];
      if (len[p] + 1 == len[q]) link[cur] = q;
      else {
        int clone = size++;
        len[clone] = len[p] + 1;
        link[clone] = link[q], next[clone] = next[q];
        while (p != -1 && next[p][c] == q)
          next[p][c] = clone, p = link[p];
        link[q] = link[cur] = clone;
      }
    }
    last = cur;
  }
  // 7
  // O(N)
  vector<int> getTerminals() {
    vector<int> terminals;
    for (int p = last; p; p = link[p])
      terminals.push_back(p);
    return terminals;
  }
};

int main() {
  string s;
  int n;
  cin >> s >> n;
  vector<int> ks(n);
  for (int i = 0; i < n; i++) cin >> ks[i];
  SuffixAutomaton sa(s);
  vector<int> dp(sa.size);

  function<int(int)> dfs = [&](int u) {
    if (dp[u]) return dp[u];
    for (auto& v : sa.next[u]) dp[u] += dfs(v.second);
    return ++dp[u];
  };

  dfs(0);

  for (auto& k : ks) {
    int u = 0;
    string ans;
    while (k) {
      for (auto& v : sa.next[u])
        if (k <= dp[v.second]) {
          ans += v.first, u = v.second, k--;
          break;
        } else
          k -= dp[v.second];
    }
    cout << ans << endl;
  };
}