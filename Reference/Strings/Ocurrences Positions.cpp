// 3
// invLink = inverse suffix-link

#include "../Data Structures/Strings/Suffix Automaton.cpp"
// 28
// O(T + OCURRENCES(ps[i]) * ps.size())
vector<vector<int>> ocurrencesPos(
    string& t, vector<string>& ps) {
  SuffixAutomaton sa(t);
  vector<vector<int>> ans, invLink(sa.size);
  for (int u = 1; u < sa.size; u++)
    invLink[sa.link[u]].push_back(u);
  function<void(int, int, vector<int>&)> dfs =
      [&](int u, int pLen, vector<int>& oc) {
        if (!sa.isClone[u])
          oc.push_back(sa.first[u] - pLen + 1);
        for (auto& v : invLink[u]) dfs(v, pLen, oc);
      };

  for (auto& p : ps)
    for (int u = 0, i = 0; i < p.size(); i++) {
      if (!sa.next[u].count(p[i])) {
        ans.push_back({});
        break;
      }
      u = sa.next[u][p[i]];
      if (i + 1 == p.size()) {
        vector<int> oc;
        dfs(u, p.size(), oc), ans.push_back(oc);
      }
    }
  return ans;
}