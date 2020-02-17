// 2
/* assumes that the bitonic point is the greastest
 * value in v*/

// 19
#include "Binary Search.cpp"

template <class T>
vector<vector<int>> bitonicSearch(vector<T> &v, T e) {
  int l = 0, r = v.size() - 1, mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (!mid || (mid >= v.size() - 1)) break;
    if (v[mid - 1] <= v[mid] && v[mid] > v[mid + 1])
      break;
    if (v[mid - 1] <= v[mid] && v[mid] <= v[mid + 1])
      l = mid + 1;
    if (v[mid - 1] > v[mid] && v[mid] > v[mid + 1])
      r = mid - 1;
  }  // at the end of the loop mid = bitonic point
  return {
      bSearch<T>(v, e, 0, mid),
      bSearch<T>(v, e, mid, v.size() - 1, false, true)};
}