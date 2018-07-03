typedef int Key;
unordered_map<int, int> id;
int nextId = 0;

int Map(Key key) { return id.count(key) ? id[key] : id[key] = nextId++; }

void initMapping() {
  nextId = 0;
  id.clear();
}