#include <stdio.h>

int main()
{
    double prec, pi = 1;
    scanf("%lf", &prec);
    double fact = 1, divider = 1, acc = 1;
    for (int i = 1; acc >= prec; ++i) {
        fact *= i;
        divider *= (2 * i + 1);
        acc = fact / divider;
        pi += acc;
    }
    pi *= 2;
    printf("%.6lf\n", pi);
    return 0;
}