// 9
vector<int> primeSieve(int n) {
  vector<int> sieve(n + 1);
  for (int i = 4; i <= n; i += 2) sieve[i] = 2;
  for (int i = 3; i * i <= n; i += 2)
    if (!sieve[i])
      for (int j = i * i; j <= n; j += 2 * i)
        if (!sieve[j]) sieve[j] = i;
  return sieve;
}