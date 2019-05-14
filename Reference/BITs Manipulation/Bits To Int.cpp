int64_t bitsToInt(string bits, bool isneg) {
  int64_t ans = 0;
  for (int i = bits.size() - 1, j = 0; ~i; i--, j++) {
    if (isneg) bits[i] = bits[i] == '0' ? '1' : '0';
    ans |= (int64_t)(bits[i] - '0') << j;
  }
  return isneg ? -(++ans) : ans;
}