#include <stdio.h>
#include <limits.h>

inline int getint()
{
    int val = 0, c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (; '0' <= c && c <= '9'; c = getchar())
        val = val * 10 + c - '0';
    return val;
}

int A[200001];

int main()
{
    int m, n, x;

    m = getint();
    for (int i = 0; i < m; i++)
        A[i] = getint();
    A[m] = INT_MAX;

    n = getint(), x = getint();
    int mid = (m + n + 1) / 2;
    int median, j = 0, rq = 1;
    for (int i = 0; i < mid; i++) {
        if (A[j] <= x)
            median = A[j++];
        else {
            median = x;
            x = ++rq <= n ? getint() : INT_MAX;
        }
    }

    printf("%d", median);

    return 0;
}
