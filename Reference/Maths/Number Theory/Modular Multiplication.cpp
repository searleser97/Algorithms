// 13
typedef __int128_t lli;

// O(lg(b))
lli multiply(lli a, lli b, lli m) {
  a %= m;
  lli ans = 0;
  while (b) {
    if (b & 1)
      ans += a, ans = (ans >= m ? ans - m : ans);
    b >>= 1, a <<= 1;
    a = (a >= m ? a - m : a);
  }
  return ans;
}