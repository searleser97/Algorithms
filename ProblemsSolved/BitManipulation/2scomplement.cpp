#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ulli;
typedef long long lli;

lli maxunsigned;

lli countCol(lli a, int col) {
	return ((lli)((a + 1ll) / (1ll << col))) * (1ll << (col - 1)) + max(0ll, ((a + 1ll) % (1ll << col)) - (1ll << (col - 1ll)));
}

lli sumcount(lli a) {
	ulli b = a;
	lli ans = 0ll;
	int col = 1;
	while (b) ans += countCol(a, col++), b >>= 1ull;
	return ans;
}

lli solution(lli a, lli b) {
	if (!a)
		return sumcount(b);
	else if (a > 0ll && b >= 0ll)
		return sumcount((unsigned) b) - sumcount((unsigned) (a - 1ll));
	else if (a < 0ll && b < 0ll)
		return sumcount((unsigned) b) - sumcount((unsigned) (a - 1ll));
	else if (a < 0ll && b >= 0ll)
		return solution(a, -1ll) + solution(0, b);
	return -1ll;
}


int main() {
	int t;
	cin >> t;
	lli a, b;
	while (t--) {
		cin >> a >> b;
		cout << solution(a, b) << endl;
	}
	return 0;
}