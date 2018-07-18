void printv(vector<int> v) {
  if (v.size() == 0) {
    cout << "[]" << endl;
    return;
  }
  cout << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    cout << ", " << v[i];
  }
  cout << "]" << endl;
}