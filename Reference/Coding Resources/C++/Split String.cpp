// 8
vector<string> split(string str, char token) {
  stringstream ss(str);
  vector<string> v;
  while (getline(ss, str, token)) v.push_back(str);
  return v;
}