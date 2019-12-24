#include <bits/stdc++.h>
using namespace std;

// #include "../Data Structures/Strings/Suffix Automaton.cpp"
// 8
struct SuffixAutomaton {
  struct State {
    int len, link;
    unordered_map<char, int> next;
  };

  vector<State> st;
  int size, last;
  // 6
  // O(N)
  SuffixAutomaton(const string& s) {
    st.resize(2 * s.size());
    st[0].len = 0, st[0].link = -1;
    size = 1, last = 0;
    for (const auto& c : s) add(c);
  }
  // 22
  // O(1)
  void add(const char& c) {
    int p = last, cur = size++;
    st[cur].len = st[p].len + 1;
    while (p != -1 && !st[p].next.count(c))
      st[p].next[c] = cur, p = st[p].link;
    if (p == -1) st[cur].link = 0;
    else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len)
        st[cur].link = q;
      else {
        int clone = size++;
        st[clone] = {st[p].len + 1, st[q].link,
                     st[q].next};
        while (p != -1 && st[p].next[c] == q)
          st[p].next[c] = clone, p = st[p].link;
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  // 7
  // O(N)
  vector<int> getTerminals() {
    vector<int> terminals;
    for (int p = last; p; p = st[p].link)
      terminals.push_back(p);
    return terminals;
  }
};

int distinctSubstrCount(const string& s) {
  SuffixAutomaton sa(s);
  vector<int> dp(sa.size, 0);
  function<int(int)> dfs = [&](int cur) {
    if (dp[cur]) return dp[cur];
    for (auto& tran : sa.st[cur].next)
      dp[cur] += dfs(tran.second);
    return ++dp[cur];
  };
  return dfs(0) - 1;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << distinctSubstrCount(s) << endl;
  }
}