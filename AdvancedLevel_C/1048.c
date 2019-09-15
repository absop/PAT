#include <stdio.h>
#include <stdlib.h>

int coins[100000];
#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }


int main()
{
    int N, pay, lo, hi, mid, sum;
    scanf("%d %d", &N, &pay);
    for (int i = 0; i < N; ++i)
        scanf("%d", &coins[i]);

    sort(coins, coins + N, cmp);
    for (; coins[N - 1] >= pay; --N);
    for (int i = 0; i < N - 1; ++i) {
        for (lo = i + 1, hi = N - 1; lo <= hi; ) {
            mid = (lo + hi) >> 1;
            sum = coins[i] + coins[mid];
            if (sum < pay)
                lo = mid + 1;
            else if (sum > pay)
                hi = mid - 1;
            else break;
        }
        if (sum == pay) {
            printf("%d %d\n", coins[i], coins[mid]);
            return 0;
        }
    }
    printf("No Solution\n");

    return 0;
}
