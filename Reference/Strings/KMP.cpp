// 3
// p = pattern, t = text
// f = error function, cf = create error function
// pos = positions where pattern is found in text
// 2
int MAXN = 1000000;
vector<int> f(MAXN + 1);
// 12
vector<int> kmp(string &p, string &t, int cf) {
  vector<int> pos;
  if (cf) f[0] = -1;
  for (int i = cf, j = 0; j < t.size();) {
    while (i > -1 && p[i] != t[j]) i = f[i];
    i++, j++;
    if (cf) f[j] = i;
    if (!cf && i == p.size())
      pos.push_back(j - i), i = f[i];
  }
  return pos;
}
// 4
vector<int> search(string &p, string &t) {
  kmp(p, p, -1);        // create error function
  return kmp(p, t, 0);  // search in text
}