#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		char n[8];
		scanf("%s", &n);
		if (n[0] == 'E') break;
		int len = strlen(n);
		for (int i = len - 1; ~i; i--) {
			if (n[i] != '0') {
				n[i]--;
				if (n[0] == '0') printf("0\n");
				else printf("%s\n", n);
				break;
			}
		}
	}
	return 0;
}