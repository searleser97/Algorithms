#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class RollingHash {
    
public:
    vector <unsigned long long int> pow;
    vector <unsigned long long int> hash;
    unsigned long long int B;
    RollingHash(const string &str) : B(257) {
        int N = str.size();
        pow.resize(N + 1);
        hash.resize(N + 1);
        pow[0] = 1;
        hash[0] = 0;
        for (int i = 1; i <= N; ++i) {
            // in c++ an unsigned long long int is automatically modulated by 2^64
            pow[i] = pow[i - 1] * B;
            hash[i] = hash[i - 1] * B + str[i - 1];
        }
    }

    unsigned long long int getWordHash() {
        return hash[hash.size() - 1];
    }

    unsigned long long int getSubstrHash(int begin, int end) {
        return hash[end] - hash[begin - 1] * pow[end - begin + 1];
    }

    int size() {
        return hash.size();
    }
};

vector<int> rabinKarp(RollingHash &rhStr, string &pattern) {
    vector<int> positions;
    RollingHash rhPattern(pattern);
    unsigned long long int patternHash = rhPattern.getWordHash();
    int windowSize = pattern.size();
    int end = windowSize;
    int limit = rhStr.size();
    for (int i = 1; end < limit; i++) {
        if (patternHash == rhStr.getSubstrHash(i, end))
            positions.push_back(i);
        end = i + windowSize;
    }
    return positions;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str, pattern;
        cin >> str;
        RollingHash rhStr(str);
        int k;
        cin >> k;
        for (int l = 0; l < k; ++l)
        {
            cin >> pattern;
            vector<int> positions = rabinKarp(rhStr, pattern);
            if (positions.size() == 0) {
                cout << "Not Found" << "\n\n";
                continue;
            }
            cout << positions.size() << '\n';
            for (int j = 0; j < positions.size(); j++) {
                cout << positions[j] << " ";
            }
            cout << "\n\n";
        }

    }
    return 0;
}