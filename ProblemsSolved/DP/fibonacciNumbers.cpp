#include<bits/stdc++.h>

using namespace std;

typedef long long int Long;

//memoization

vector<Long> memo(1000);

Long fib(Long n) {
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

Long fibIterative(Long n) {
    for (Long i = 1; i <= n; i++) {
        if (i < 3)
            memo[i] = 1;
        else
            memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main () {
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    Long n;
    cin >> n;
    cout << fibIterative(n) << endl;
}