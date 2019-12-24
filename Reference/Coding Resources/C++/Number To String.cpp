// 10
#include <bits/stdc++.h>
using namespace std;

int main() {
  // to_string method converts any type of number
  // (int, double, long long int, ...) to string
  string str = "str+" + to_string(123 + 1);
  cout << str << endl;  // output: str+124
  return 0;
}