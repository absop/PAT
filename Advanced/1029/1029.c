#include <stdio.h>

int k[200001];

#define TEST_RETURN(x)       \
    if (++count == midpos) { \
        printf("%d", x);     \
        return 0;            \
    }

int main()
{
    int n, m, temp, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
    k[n] = 0x7fffffff;
    scanf("%d", &m);
    int midpos = (n + m + 1) / 2, i = 0;
    for (int j = 0; j < m; ++j) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            TEST_RETURN(k[i])
            ++i;
        }
        TEST_RETURN(temp)
    }
    while (i < n) {
        TEST_RETURN(k[i])
        ++i;
    }
    return 0;
}
