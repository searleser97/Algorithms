// 10
typedef __int128_t lli

lli bitsToInt(string bits, bool isneg) {
  lli ans = 0;
  for (int i = bits.size() - 1, j = 0; ~i; i--, j++) {
    if (isneg) bits[i] = bits[i] == '0' ? '1' : '0';
    ans |= (lli)(bits[i] - '0') << j;
  }
  return isneg ? -(++ans) : ans;
}