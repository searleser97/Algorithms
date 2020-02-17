// 10
// ans[0] = true if e is in v else false
// ans[1] = index pointing to the first element in
// the range [l, r) which compares > to e.
template <class T>
vector<int> upperBound(vector<T>& v, T e, int l,
                       int r) {
  auto it = v.begin();
  int i = upper_bound(it + l, it + r, e) - it;
  return {v[i - 1] == e, i};
}