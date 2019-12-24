#include <bits/stdc++.h>

using namespace std;

typedef int64_t T;

int main() {
	int t;
	scanf("%d", &t);
	for (int y = 1; y <= t; y++) {
		T n, c = 0;
		scanf("%lld", &n);
		bool flag = true;
		for (int k = 1; k * (k + 1) < 2 * n; k++) {
			double x = (n - (k * (k + 1.0)) / 2.0) / (k + 1.0);
			if (floor(x) == x) c++;
		}
		printf("case %d: %d\n", y, c);
	}
	return 0;
}