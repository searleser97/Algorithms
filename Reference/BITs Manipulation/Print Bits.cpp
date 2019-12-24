// 5
void printBits(int n) {
  for (int i = sizeof(n) * 8 - 1; ~i; i--)
    cout << ((n >> i) & 1);
  cout << endl;
}