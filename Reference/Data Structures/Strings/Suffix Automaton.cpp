// 4
// link[u]: links to the longest suffix which is
//          not in the same endpos-equivalence class
// len[u]: length of the longest suffix that
//         corresponds to u's endpos-equivalence class
// 4
struct SuffixAutomaton {
  vector<int> len, link, isClone, first;
  vector<map<char, int>> next;
  int size, last;
  // 5
  void init(int n) {
    first = isClone = len = link = vector<int>(2 * n);
    next.resize(2 * n);
    len[0] = 0, link[0] = -1, size = 1, last = 0;
  }
  // 5
  // O(N)
  SuffixAutomaton(const string& s) {
    init(s.size());
    for (const auto& c : s) add(c);
  }
  // 22
  // O(1)
  void add(const char& c) {
    int p = last, u = size++;
    len[u] = len[p] + 1, first[u] = len[p];
    while (p != -1 && !next[p].count(c))
      next[p][c] = u, p = link[p];
    if (p == -1) link[u] = 0;
    else {
      int q = next[p][c];
      if (len[p] + 1 == len[q]) link[u] = q;
      else {
        int clone = size++;
        first[clone] = first[q];
        len[clone] = len[p] + 1, isClone[clone] = 1;
        link[clone] = link[q], next[clone] = next[q];
        while (p != -1 && next[p][c] == q)
          next[p][c] = clone, p = link[p];
        link[q] = link[u] = clone;
      }
    }
    last = u;
  }
  // 7
  // O(N)
  unordered_set<int> getTerminals() {
    unordered_set<int> terminals;
    for (int p = last; p; p = link[p])
      terminals.insert(p);
    return terminals;
  }
};