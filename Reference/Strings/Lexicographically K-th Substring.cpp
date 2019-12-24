// 13
#include "../Data Structures/Strings/Suffix Automaton.cpp"
// 9
// O(N * ks.size)
vector<string> kthSubstr(string& s, vector<int>& ks) {
  SuffixAutomaton sa(s);
  vector<int> dp(sa.size);
  function<int(int)> dfs = [&](int u) {
    if (dp[u]) return dp[u];
    for (auto& v : sa.next[u]) dp[u] += dfs(v.second);
    return ++dp[u];
  };
  // 16
  dfs(0);
  vector<string> ans;
  for (auto k : ks) {
    int u = 0;
    string ss;
    while (k)
      for (auto& v : sa.next[u])
        if (k <= dp[v.second]) {
          ss += v.first, u = v.second, k--;
          break;
        } else
          k -= dp[v.second];
    ans.push_back(ss);
  }
  return ans;
}