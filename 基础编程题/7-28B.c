#include <stdio.h>

// 数学解法，无需额外内存
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) sum = (sum + 3) % i;
    printf("%d\n", sum + 1);
}
