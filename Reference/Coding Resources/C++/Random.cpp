// 8
mt19937_64 seed(chrono::steady_clock::now()
                    .time_since_epoch()
                    .count());

int random(int min, int max) {  // [min, max]
  return uniform_int_distribution<int>(min,
                                       max)(seed);
}
// 4
double random(double min, double max) {  // [min, max)
  return uniform_real_distribution<double>(min,
                                           max)(seed);
}