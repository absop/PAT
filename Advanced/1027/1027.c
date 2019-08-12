#include <stdio.h>

#define X(x) x / 13, x % 13

int main()
{
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#%X%X%X%X%X%X\n", X(r), X(g), X(b));
}
