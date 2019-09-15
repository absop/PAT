#include <stdio.h>

int accs[100001], pairs[100001][2], cnt;
#define sum(i, j) (accs[j] - accs[i - 1])

int main()
{
    int N, pay;
    scanf("%d %d", &N, &pay);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &accs[i]);
        accs[i] += accs[i - 1];
    }

    int lo, hi, acc, mid, minacc = accs[N];
    for (int i = 1, j = i; i <= N && sum(i, N) >= pay; ++i) {
        for (lo = j, hi = N; lo < hi;) {
            mid = (lo + hi) >> 1;
            if (sum(i, mid) >= pay) hi = mid;
            else lo = mid + 1;
        }
        acc = sum(i, hi);
        j = i > hi ? i : hi;
        if (acc > minacc) continue;
        if (acc < minacc) {
            minacc = acc;
            cnt = 0;
        }
        pairs[cnt][0] = i;
        pairs[cnt][1] = hi;
        ++cnt;
    }
    for (int i = 0; i < cnt; ++i)
        printf("%d-%d\n", pairs[i][0], pairs[i][1]);

    return 0;
}
