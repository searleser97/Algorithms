int main() {
  int t;
  scanf("%d", &t);
  for (int j = 1; j <= t; j++) {
    lli x;
    scanf("%lld", &x);
    lli count = 0;
    V divisors = getDivisors(2LL * x);
    for (auto &div : divisors) {
      double d =
          ((double)x / div) + ((1.00 - div) / 2.00);
      if (d > 0 && div > 1 && d == floor(d) &&
          div < x &&
          (2 * d * div + (div - 1) * div == 2 * x)) {
        count++;
      }
    }
    printf("case %d: %lld\n", j, count);
  }
}