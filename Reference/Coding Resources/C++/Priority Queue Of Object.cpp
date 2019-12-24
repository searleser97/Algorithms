// 4
struct Object {
  char first;
  int second;
};
// 8
int main() {
  auto cmp = [](const Object& a, const Object& b) {
    return a.second > b.second;
  };
  priority_queue<Object, vector<Object>,
                 decltype(cmp)>
      pq(cmp);
}