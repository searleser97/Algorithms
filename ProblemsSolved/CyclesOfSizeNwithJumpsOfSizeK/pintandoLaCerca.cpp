#include <stdio.h>

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (d < a || c > b)
        printf("%d\n", b - a + d - c);
    else
        printf("%d\n", max(b, d) - min(a, c));
    return 0;
}
