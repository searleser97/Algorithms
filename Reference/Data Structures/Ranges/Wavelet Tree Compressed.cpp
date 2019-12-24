// 11
// lte = less than or equal, c = compressed
// o  = original, 0-indexed
#include "../../Techniques/Binary Search.cpp"
#include "Wavelet Tree.cpp"

template <class T>
struct WaveletTreeCompressed {
  unordered_map<int, T> imap;
  unordered_map<T, int> Map;
  WaveletTree* wt;
  vector<T> o;
  // 12
  // O(N*lg(N))
  WaveletTreeCompressed(vector<T>& v) {
    o = v;
    int inf = 1 << 30, n = 0, lo = inf, hi = -inf;
    set<T> s(v.begin(), v.end());
    vector<int> c(v.size());
    for (auto& e : s) Map[e] = n++;
    for (int i = 0; i < v.size(); i++)
      c[i] = Map[v[i]], imap[Map[v[i]]] = v[i];
    for (auto& e : c)
      lo = min(lo, e), hi = max(hi, e);
    wt = new WaveletTree(c.begin(), c.end(), lo, hi);
  }
  // 4
  // O(lg(N)) frequency of k in [a, b]
  int freq(int l, int r, T k) {
    return wt->freq(++l, ++r, Map[k]);
  }
  // 4
  // O(lg(N)) kth-Smallest element in [l, r]
  T kth(int l, int r, int k) {
    return imap[wt->kth(++l, ++r, k)];
  }
  // 5
  // O(lg(N)) count of numbers <= to k in [l, r]
  T lte(int l, int r, T k) {
    int kk = Map[bSearch<T>(o, k, l, r)[1]];
    return imap[wt->lte(++l, ++r, kk)];
  }
  // 5
  // O(lg(N)) sum of numbers <= to k in [l, r]
  T sumlte(int l, int r, T k) {
    int kk = Map[bSearch<T>(o, k, l, r)[1]];
    return imap[wt->sumlte(++l, ++r, kk)];
  }
};