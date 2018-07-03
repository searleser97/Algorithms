typedef long long int lli;

lli bitsInInt(lli n) { return floor(log2(n) + 1LL); }

vector<int> intToBitsArray(lli n) {
  n = abs(n);
  if (!n) {
    vector<int> v;
    return v;
  }
  int length = bitsInInt(n);
  int lastPos = length - 1;
  vector<int> v(length);
  for (lli i = lastPos, j = 0; i > -1LL; i--, j++) {
    lli aux = (n >> i) & 1LL;
    v[j] = aux;
  }
  return v;
}
