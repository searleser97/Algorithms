typedef string Key;
unordered_map<Key, int> val;
unordered_map<int, Key> getKey;
int mapId = 0;

int Map(Key key) {
  getKey[mapId] = key;
  return val.count(key) ? val[key]
                        : val[key] = mapId++;
}

void initMapping() {
  mapId = 0;
  val.clear();
}