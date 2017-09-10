#include <bits/stdc++.h>
using namespace std;
/*
the problem is to find the kth smallest number in the multiplication table (n rows, m columns)
for k = 9 the answer is 5
to solve it:
the idea is to guess a number between 1 and n * m, lets call this number mid and
count the numbers up to mid (including repetitions) with the following conditions:
// every number below mid / m_i will be bigger than mid, so:
    if mid / m_i( = 1,2,...,m) = maxNumberReachedPerColumn > n, then
        count += n
    else
        count += maxNumberReachedPerColumn
now that we have the count of numbers lesser than mid
we check:
    if (count > k)
        we discard 
*/
int main() {
    long long int n, m , k, l , r;
    cin >> n >> m >> k;
    l = 1;
    r = m * n;
    while(l <= r) {
        long long int mid = (l + r) / 2;
        long long int count = 0;
        for (long long int i = 1; i <= m; i++) {
            long long int maxInColumn = mid / i;
            if (maxInColumn > n)
                count += n;
            else
                count += maxInColumn;
        }
        if (count < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
