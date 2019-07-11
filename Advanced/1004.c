#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
#define MAXM 100
#define max(a, b) ((a) > (b)? (a): (b))

int table[100][100];
int count[100], Nchild[100];
int Nlevel;

void dfs(x, level)
{
    if (Nchild[x] == 0) {
        count[level]++;
        Nlevel = max(Nlevel, level);
        return;
    }
    for (int i = 0; i < Nchild[x]; ++i)
        dfs(table[x][i], level + 1);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int ID, k, IDi;
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &ID, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &IDi);
            table[ID][Nchild[ID]++] = IDi;
        }
    }

    dfs(1, 0);

    printf("%d", count[0]);
    for (int i = 1; i <= Nlevel; ++i)
        printf(" %d", count[i]);
    printf("\n");

    return 0;
}
