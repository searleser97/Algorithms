// 4
struct Object {
  char first;
  int second;
};
// 10
int main() {
  auto cmp = [](const Object& a, const Object& b) { return a.second > b.second; };
  priority_queue<Object, vector<Object>, decltype(cmp)> pq(cmp);
  vector<Object> v = {{'c', 3}, {'a', 1}, {'b', 2}};
  sort(v.begin(), v.end(), cmp);
  return 0;
}