// 15
// ans[0] = true if e is in v else false
// ans[1] = index pointing to the first element in
// the range [l, r] which compares >= to e.

// O(lg(r - l)) [l, r]
template <class T>
vector<int> lowerBound(vector<T>& v, T e, int l,
                       int r) {
  int rr = r;
  while (l <= r) {
    int mid = l + (r - l) >> 1;
    e <= v[mid] ? r = mid - 1, l = mid + 1;
  }
  return {v[min(rr, l)] == e, l};
}