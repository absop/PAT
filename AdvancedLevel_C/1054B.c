// 王道数据结构2020，P26
#include <stdio.h>

int getint(int *x)
{
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (*x = c - '0'; c = getchar(), '0' <= c && c <= '9'; )
        *x = *x * 10 + c - '0';
}

int main()
{
    int m, n, x, dominant;
    getint(&m), getint(&n);
    getint(&dominant);
    int pro = m * n, count = 1;
    for (int i = 1; i < pro; ++i) {
        getint(&x);
        if (x == dominant)
            ++count;
        else if (count > 0)
            --count;
        else {
            dominant = x;
            count = 1;
        }
    }
    printf("%d\n", dominant);

    return 0;
}
