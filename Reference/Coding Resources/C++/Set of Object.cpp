// 4
struct Object {
  char first;
  int second;
};
// 6
int main() {
  auto cmp = [](const Object& a, const Object& b) {
    return a.second > b.second;
  };
  set<Object, decltype(cmp)> pq(cmp);
}