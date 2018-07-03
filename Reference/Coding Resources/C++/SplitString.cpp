vector<string> split(string str, char token) {
  stringstream test(str);
  string seg;
  vector<string> seglist;
  while (getline(test, seg, token)) seglist.push_back(seg);
  return seglist;
}