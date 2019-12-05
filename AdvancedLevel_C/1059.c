#include <stdio.h>
#include <string.h>

#define MAXFACTOR 50000

int isPrime[MAXFACTOR] = { [0 ... MAXFACTOR - 1] = 1 };

int main()
{
    long int n, cnt, star = 0;

    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) printf("1");

    for (int i = 2; i * i < MAXFACTOR; i++)
        for (int j = 2; j * i < MAXFACTOR; j++)
            isPrime[j * i] = 0;

    for (int i = 2; n >= 2; i++) {
        if (!isPrime[i]) continue;
        for (cnt = 0; n % i == 0; ++cnt)
            n = n / i;
        if (cnt) {
            if (star) putchar('*');
            printf("%d", i);
            if (cnt >= 2)
                printf("^%d", cnt);
            star = 1;
        }
    }

    return 0;
}
