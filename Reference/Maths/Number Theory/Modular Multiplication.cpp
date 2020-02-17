// 13
typedef long long int li;

// O(lg(b))
li multiply(li a, li b, li m) {
  a %= m;
  li ans = 0;
  while (b) {
    if (b & 1)
      ans += a, ans = (ans >= m ? ans - m : ans);
    b >>= 1, a <<= 1;
    a = (a >= m ? a - m : a);
  }
  return ans;
}