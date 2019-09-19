#include <stdio.h>

int main()
{
    char v[100001], A;
    int N, x, len = 0, carry = 0;
    scanf("%d %d", &A, &N);

    for (int i = N; i >= 1; --i) {
        x = carry + A * i;
        carry = x / 10;
        v[len++] = x % 10;
    }
    for (; carry; carry /= 10)
        v[len++] = carry % 10;

    if (len > 0)
        for (; --len >= 0; )
            putchar(v[len] + '0');
    else
        putchar('0');
}
