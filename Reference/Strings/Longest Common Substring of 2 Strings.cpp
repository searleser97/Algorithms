// 14
#include "../Data Structures/Strings/Suffix Automaton.cpp"

string lcs(string& a, string& b) {
  SuffixAutomaton sa(a);
  int bestLen = 0, bestPos = -1;
  for (int i = 0, u = 0, l = 0; i < b.size(); i++) {
    while (u && !sa.next[u].count(b[i]))
      u = sa.link[u], l = sa.len[u];
    if (sa.next[u].count(b[i]))
      u = sa.next[u][b[i]], l++;
    if (l > bestLen) bestLen = l, bestPos = i;
  }
  return b.substr(bestPos - bestLen + 1, bestLen);
}