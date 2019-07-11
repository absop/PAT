#include <stdio.h>

int gcd(int a, int b);

int main()
{
    int a, b, g;
    scanf("%d/%d", &a, &b);
    g = gcd(a, b);
    printf("%d/%d\n", a / g, b / g);
}

inline int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}