// 9
typedef int T;

struct pairhash {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>{}(p.first) ^
           (hash<T2>{}(p.second) << 32);
  }
};
// 5
int main() {
  unordered_map<pair<int, int>, T, hash_pair> um;
  um[{1, 2}] = 5;
  cout << um[{1, 2}] << endl;
}