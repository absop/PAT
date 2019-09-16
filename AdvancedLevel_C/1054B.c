// 王道数据结构2020，P26
#include <stdio.h>

inline int getint()
{
    int val = 0, c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (; '0' <= c && c <= '9'; c = getchar())
        val = val * 10 + c - '0';
    return val;
}

int main()
{
    int m, n, x, dominant;
    m = getint(), n = getint();
    dominant = getint();
    int pro = m * n, count = 1;
    for (int i = 1; i < pro; ++i) {
        x = getint();
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
