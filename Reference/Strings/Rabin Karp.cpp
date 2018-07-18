class RollingHash {
 public:
  vector<unsigned long long int> pow;
  vector<unsigned long long int> hash;
  unsigned long long int B;
  RollingHash(const string &text) : B(257) {
    int N = text.size();
    pow.resize(N + 1);
    hash.resize(N + 1);
    pow[0] = 1;
    hash[0] = 0;
    for (int i = 1; i <= N; ++i) {
      // in c++ an unsigned long long int is
      // automatically modulated by 2^64
      pow[i] = pow[i - 1] * B;
      hash[i] = hash[i - 1] * B + text[i - 1];
    }
  }

  unsigned long long int getWordHash() {
    return hash[hash.size() - 1];
  }

  unsigned long long int getSubstrHash(int begin,
                                       int end) {
    return hash[end] -
           hash[begin - 1] * pow[end - begin + 1];
  }

  int size() {
    return hash.size();
  }
};

vector<int> rabinKarp(RollingHash &rhStr,
                      string &pattern) {
  vector<int> positions;
  RollingHash rhPattern(pattern);
  unsigned long long int patternHash =
      rhPattern.getWordHash();
  int windowSize = pattern.size(),
      end = windowSize;
  for (int i = 1; end < rhStr.size(); i++) {
    if (patternHash ==
        rhStr.getSubstrHash(i, end))
      positions.push_back(i);
    end = i + windowSize;
  }
  return positions;
}