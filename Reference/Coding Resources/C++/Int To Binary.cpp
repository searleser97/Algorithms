typedef long long int lli;
//3
lli bitsInInt(lli n) { // clz = count leading zeroes
  return sizeof(n) * 8 - __builtin_clzll(n);
}
//9
vector<bool> intToBitsArray(lli n) {
  n = abs(n);
  if (!n) return {};
  int length = bitsInInt(n), lastPos = length - 1;
  vector<bool> v(length);
  for (lli i = lastPos, j = 0; i > -1LL; i--, j++) v[j] = (n >> i) & 1LL;
  return v;
}