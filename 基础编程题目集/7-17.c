#include <stdio.h>
#include <math.h>

int main()
{
    int N, U, D;
    int minutes = 0;
    scanf("%d %d %d", &N, &U, &D);

    while (N > 0) {
        minutes += 1;
        N -= U;
        if (N <= 0)break;
        minutes += 1;
        N += D;
    }
    printf("%d\n", minutes);

    return 0;
}
