// val = value
typedef string Val;
unordered_map<Val, int> intForVal;
unordered_map<int, Val> valForInt;
int mapId = 0;

int Map(Val val) {
  valForInt[mapId] = val;
  return intForVal.count(val) ? intForVal[val] : intForVal[val] = mapId++;
}

int IMap(int val) {
  return valForInt[val];
}

void initMapping() {
  mapId = 0;
  intForVal.clear();
  valForInt.clear();
}