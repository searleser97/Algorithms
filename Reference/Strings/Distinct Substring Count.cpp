// 13
#include "../Data Structures/Strings/Suffix Automaton.cpp"

// O(N)
int distinctSubstrCount(const string& s) {
  SuffixAutomaton sa(s);
  vector<int> dp(sa.size);
  function<int(int)> dfs = [&](int u) {
    if (dp[u]) return dp[u];
    for (auto& v : sa.next[u]) dp[u] += dfs(v.second);
    return ++dp[u];
  };
  return dfs(0) - 1;
}