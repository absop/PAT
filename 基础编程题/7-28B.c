#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) sum = (sum + 3) % i;
    printf("%d\n", sum + 1);
}
