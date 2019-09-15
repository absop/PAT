/* Copy from:
 * https://github.com/liuchuo/PAT */
#include <stdio.h>

int a[1001];
int main()
{
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= m >> 1; i++) {
        if (a[i]-- && a[m - i]) {
            printf("%d %d", i, m - i);
            return 0;
        }
    }
    printf("No Solution");

    return 0;
}
