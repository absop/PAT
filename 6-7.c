#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i = n1; i <= n2; i++ ) {
        if ( IsTheNumber(i) )
          printf("%d\n", i);
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber ( const int N )
{
    int isqrt = (int)sqrt(N);
    if (isqrt * isqrt == N) {
        int d[10] = { -1}, i = 0, N1 = N;
        while (N1 > 0) {
            d[i++] = N1 % 10;
            N1 /= 10;
        }
        for (int j = 0; j < i - 1; ++j) {
            for (int k = j + 1; k < i; ++k) {
                if (d[k] == d[j])
                    return 1;
            }
        }
    }
    return 0;
}