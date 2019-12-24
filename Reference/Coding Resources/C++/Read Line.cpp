// 8
// when reading lines, don't mix 'cin' with
// 'getline' just use getline and split
string input() {
  string ans;
  cin >> ws;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, ans);
  return ans;
}