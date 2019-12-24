// 14
#include "../Data Structures/Strings/Suffix Automaton.cpp"

// O(N)
string smallestCyclicShift(const string& s) {
  SuffixAutomaton sa(s + s);
  int k = s.size(), u = 0;
  string ans;
  while (k)
    for (auto& v : sa.next[u]) {
      ans += v.first, u = v.second, k--;
      break;
    }
  return ans;
}