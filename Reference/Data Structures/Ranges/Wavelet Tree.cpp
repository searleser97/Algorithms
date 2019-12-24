// 8
// pref = prefix sum
// lte = less than or equal, 1-indexed
// A = max_element(from, to)
// lcount = left children count
struct WaveletTree {
  WaveletTree *l, *r;
  int lo, hi;
  vector<int> lcount, pref;
  // 17
  // O(N*lg(A))
  WaveletTree(vector<int>::iterator from,
              vector<int>::iterator to, int lo,
              int hi) {
    this->lo = lo, this->hi = hi;
    if (lo == hi or from >= to) return;
    int mid = (lo + hi) >> 1;
    auto f = [mid](int x) { return x <= mid; };
    lcount.reserve(to - from + 1);
    pref.reserve(to - from + 1);
    lcount.push_back(0);
    pref.push_back(0);
    for (auto it = from; it != to; it++)
      lcount.push_back(lcount.back() + f(*it)),
          pref.push_back(pref.back() + *it);
    auto pivot = stable_partition(from, to, f);
    l = new WaveletTree(from, pivot, lo, mid);
    r = new WaveletTree(pivot, to, mid + 1, hi);
  }
  // 9
  // O(lg(A)) frequency of k in [a, b]
  int freq(int a, int b, int k) {
    if (a > b or k < lo or k > hi) return 0;
    if (lo == hi) return b - a + 1;
    int lc = lcount[a - 1], rc = lcount[b];
    if (k > ((lo + hi) >> 1))
      return r->freq(a - lc, b - rc, k);
    return l->freq(lc + 1, rc, k);
  }
  // 10
  // O(lg(A)) kth-Smallest element in [a, b]
  int kth(int a, int b, int k) {
    if (a > b) return 0;
    if (lo == hi) return lo;
    int lc = lcount[a - 1], rc = lcount[b],
        inleft = rc - lc;
    if (k > inleft)
      return r->kth(a - lc, b - rc, k - inleft);
    return l->kth(lc + 1, rc, k);
  }
  // 8
  // O(lg(A)) count of elements <= to k in [a, b]
  int lte(int a, int b, int k) {
    if (a > b or k < lo) return 0;
    if (hi <= k) return b - a + 1;
    int lc = lcount[a - 1], rc = lcount[b];
    return l->lte(lc + 1, rc, k) +
           r->lte(a - lc, b - rc, k);
  }
  // 8
  // O(lg(A)) sum of numbers <= to k in [a, b]
  int sumlte(int a, int b, int k) {
    if (a > b or k < lo) return 0;
    if (hi <= k) return pref[b] - pref[a - 1];
    int lc = lcount[a - 1], rc = lcount[b];
    return l->sumlte(lc + 1, rc, k) +
           r->sumlte(a - lc, b - rc, k);
  }
};