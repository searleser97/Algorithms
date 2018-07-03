// when reading lines, don't mix 'cin' with 'getline'
// just use getline and split
string input() {
  string ans;
  // cin >> ws; // eats all whitespaces.
  getline(cin, ans);
  return ans;
}
