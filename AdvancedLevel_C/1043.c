#include <stdio.h>
#include <stdlib.h>

int cnt;
int pre[1001], post[1001];

#define MAKEPOSTFUNC(funcname, cmp1, cmp2) \
void funcname(int root, int tail)                               \
{                                                               \
    if (root > tail) return;                                    \
    int i, j;                                                   \
    for (i = root + 1; i <= tail && pre[root] cmp1 pre[i]; ++i);\
    for (j = tail; j > root && pre[root] cmp2 pre[j]; --j);     \
    if (i - j == 1) {                                           \
        funcname(root + 1, j);                                  \
        funcname(i, tail);                                      \
        post[cnt++] = pre[root];                                \
    }                                                           \
}

MAKEPOSTFUNC(getpost1, >, <= )
MAKEPOSTFUNC(getpost2, <=, > )

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &pre[i]);
    getpost1(0, N - 1);
    if (cnt != N) {
        cnt = 0;
        getpost2(0, N - 1);
    }
    if (cnt == N) {
        printf("YES\n");
        const char *fmts[2] = {"%d", " %d"};
        for (int i = 0; i < N; ++i)
            printf(fmts[!!i], post[i]);
    }
    else printf("NO\n");

    return 0;
}
