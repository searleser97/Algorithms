// 13
typedef long long int li;
// if li == __int128_t: use map<li, int> Map;
typedef unordered_map<li, int> Map;

// ~O(sqrt(N) * lg(N))
Map getPrimeFactors(li n) {
  Map pf;
  while (~n & 1) pf[2]++, n >>= 1;
  for (li i = 3; i * i <= n; i += 2)
    while (!(n % i)) pf[i]++, n /= i;
  if (n > 1) pf[n]++;
  return pf;
}