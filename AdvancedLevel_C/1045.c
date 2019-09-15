/* Copy from:
 * https://github.com/liuchuo/PAT */
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int frank[201], ranks[10001], dp[10001];

int main()
{
    int n, m, l, x, num = 0, maxn = 0;
    scanf("%d\n%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &x);
        frank[x] = i;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &x);
        if (frank[x] >= 1)
            ranks[num++] = frank[x];
    }
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (ranks[i] >= ranks[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);

    return 0;
}
