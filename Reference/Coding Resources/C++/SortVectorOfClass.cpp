struct Object {
  char first;
  int second;
};

bool cmp(const Object& a, const Object& b) {
  return a.second > b.second;
}

int main() {
  vector<Object> v = {
      {'c', 3}, {'a', 1}, {'b', 2}};
  sort(v.begin(), v.end(), cmp);
  printv(v);
  return 0;
}