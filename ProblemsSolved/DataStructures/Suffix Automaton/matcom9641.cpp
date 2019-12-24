#include <bits/stdc++.h>
using namespace std;
// 8

struct SuffixAutomaton {
  struct State {
    int len, link;
    unordered_map<char, int> next;
  };

  // State st[2 * 1000000];
  vector<State> st;
  int sz, last;
  // 6
  // O(N)
  SuffixAutomaton(const string& s) {
    st.resize(2 * s.size());
    st[0].len = 0, st[0].link = -1;
    sz = 1, last = 0;
    for (const auto & c : s) add(c);
  }
  // 22
  // O(1)
  void add(const char& c) {
    int p = last, cur = sz++;
    st[cur].len = st[p].len + 1;
    while (p != -1 && !st[p].next.count(c))
      st[p].next[c] = cur, p = st[p].link;
    if (p == -1) st[cur].link = 0;
    else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len)
        st[cur].link = q;
      else {
        int clone = sz++;
        st[clone] = {st[p].len + 1, st[q].link,
                     st[q].next};
        while (p != -1 && st[p].next[c] == q)
          st[p].next[c] = clone, p = st[p].link;
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
};

int process(string &str, SuffixAutomaton & sa) {
  unordered_map<char, int> tran = sa.st[0].next;
  int ans = 1;
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (!sa.st[0].next.count(c)) return -1;
    if (tran.count(c))
      tran = sa.st[tran[c]].next;
    else {
      ans++;
      i--;
      tran = sa.st[0].next;
    }
  }
  return ans;
}

int main() { 
  string in;
  int n;
  cin >> in >> n;
  SuffixAutomaton sa(in);
  while(n--) {
    string str;
    cin >> str;
    cout << process(str, sa) << endl;
  }
  return 0; 
}