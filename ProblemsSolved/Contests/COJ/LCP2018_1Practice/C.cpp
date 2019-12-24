#include <bits/stdc++.h>

using namespace std;

typedef int64_t T;

int main() {
	T t;
	scanf("%lld", &t);
	while (t--) {
		T n;
		scanf("%lld", &n);
		bool flag = true;
		for (int k = 1; k * (k + 1) < 2 * n; k++) {
			double x = (n - (k * (k + 1.0)) / 2.0) / (k + 1.0);
			if (floor(x) == x) {
				printf("%d = %d", n, (int) x);
				for (T i = ++x; i < x + k; i++)
					printf(" + %d", i);
				printf("\n");
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}