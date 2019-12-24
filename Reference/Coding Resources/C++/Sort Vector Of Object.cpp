// 4
struct Object {
  char first;
  int second;
};
// 3
bool cmp(const Object& a, const Object& b) {
  return a.second > b.second;
}
// 6
int main() {
  vector<Object> v = {{'c', 3}, {'a', 1}, {'b', 2}};
  sort(v.begin(), v.end(), cmp);
}