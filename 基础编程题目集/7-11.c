#include <stdio.h>


int main()
{
    double x, y;
    scanf("%lf", &x);
    printf("%.2lf\n", x > 15 ? 2.5 * x - 17.5 : 4 * x / 3);
}