// 5
// val = value
typedef string Val;
unordered_map<Val, int> intForVal;
unordered_map<int, Val> valForInt;
int mapId = 0;
// 5
int Map(Val val) {
  if (intForVal.count(val)) return intForVal[val];
  valForInt[mapId] = val;
  return intForVal[val] = mapId++;
}

Val IMap(int n) { return valForInt[n]; }
// 5
void initMapping() {
  mapId = 0;
  intForVal.clear();
  valForInt.clear();
}