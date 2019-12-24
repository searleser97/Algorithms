// 10
/* if e in v and lower = false (upper_bound):
  r = position of e in v
  l = r + 1
if e in v and lower = true (lower_bound):
  l = position of e in v
  r = l - 1
if e not in v and inv = false it means that:
  v[r] < e < v[l]
if e not in v and inv = true it means that:
  v[r] > e > v[l] */
// 16
// O(lg(r - l)) [l, r]
template <class T>
vector<T> bSearch(vector<T> &v, T e, int l, int r,
                  bool lower = 0, bool inv = 0) {
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (e < v[mid])
      inv ? l = mid + 1 : r = mid - 1;
    else if (e > v[mid])
      inv ? r = mid - 1 : l = mid + 1;
    else
      lower ? r = mid - 1 : l = mid + 1;
  }  // bSearch[0] tells if the element was found
  return {lower ? v[l] == e : v[r] == e, r, l};
}  // be aware that r can be < given l and l > given r