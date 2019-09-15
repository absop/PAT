/* Inspired by the same problem under:
 * https://github.com/tiny656/PAT */
#include <stdio.h>
int fav[201], dp[201];

int main()
{
    int n, m, l, x;
    scanf("%d\n%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &fav[i]);

    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= m; j++) {
            if (dp[j - 1] > dp[j])
                dp[j] = dp[j - 1];
            if (x == fav[j])
                dp[j]++;
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}
