#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n = 2;
    double a[3] = {1, 2.5, -38.7}, x = 1.1;

    printf("%lf\n", f(n, a, x));
    return 0;
}

double f(int n, double a[], double x)
{
    double result = 0;
    for (int i = n; i >= 0; --i) {
        result *= x;
        result += a[i];
    }
    return result;
}