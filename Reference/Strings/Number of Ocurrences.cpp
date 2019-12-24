// 4
// t: text, ps: patterns
// cnt[u]: size of u's endpos set

#include "../Data Structures/Strings/Suffix Automaton.cpp"
// 24
// O(T * Lg(T) + p.size() * ps.size())
vector<int> nOcurrences(string& t,
                        vector<string>& ps) {
  SuffixAutomaton sa(t);
  vector<int> cnt(sa.size), aux(sa.size), ans;
  for (int u = 0; u < sa.size; aux[u] = u, u++)
    if (!sa.isClone[u]) cnt[u] = 1;
  sort(aux.begin(), aux.end(), [&](int& a, int& b) {
    return sa.len[b] < sa.len[a];
  });
  for (auto& u : aux)
    if (u) cnt[sa.link[u]] += cnt[u];
  for (auto& p : ps)
    for (int u = 0, i = 0; i < p.size(); i++) {
      if (!sa.next[u].count(p[i])) {
        ans.push_back(0);
        break;
      }
      u = sa.next[u][p[i]];
      if (i + 1 == p.size()) ans.push_back(cnt[u]);
    }
  return ans;
}