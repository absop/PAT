#include <stdio.h>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    int hi = n / 10, cu = n % 10, lo = 0;
    for (int d = 1; n / d; d *= 10) {
        cnt += hi * d;
        if (cu > 1)
            cnt += d;
        else if (cu == 1)
            cnt += lo + 1;
        lo = lo + cu * d;
        cu = hi % 10;
        hi = hi / 10;
    }
    printf("%d", cnt);
    return 0;
}
