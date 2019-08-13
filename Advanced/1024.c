#include <stdio.h>


int main()
{
    char N[64], RN[64];
    int k, cnt, len = 0;
    scanf("%s %d", N, &k);

    while (N[len]) N[len++] -= '0';
    for (int i = 0, j = len - 1; i < len; RN[j--] = N[i++]);
    for (RN[len] = 0, cnt = 0; cnt < k; ++cnt) {
        int lo = 0, hi = len - 1;
        for (; lo < hi && RN[lo] == RN[hi]; ++lo, --hi);
        if (lo >= hi) break;
        for (int i = 0, j = len - 1; i < len; N[j--] = RN[i++]);
        for (int i = 0; i < len; ++i) {
            RN[i] += N[i];
            RN[i + 1] += RN[i] / 10;
            RN[i] %= 10;
        }
        if (RN[len] != 0) RN[++len] = 0;
    }

    while (--len >= 0)putchar(RN[len] + '0');
    printf("\n%d", cnt);

    return  0;
}
