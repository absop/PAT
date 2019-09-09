#include <stdio.h>
#include <stdlib.h>

int table[100][100];
int count[100], Nchild[100];
int Nlevel;

void dfs(x, level)
{
    if (Nchild[x] == 0) {
        count[level]++;
        if (level > Nlevel) Nlevel = level;
        return;
    }
    for (int i = 0; i < Nchild[x]; ++i)
        dfs(table[x][i], level + 1);
}

int main()
{
    int N, M, ID, k, cnt = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &ID, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &table[ID][Nchild[ID]++]);
        }
    }

    dfs(1, 0);

    printf("%d", count[0]);
    for (int i = 1; i <= Nlevel; ++i)
        printf(" %d", count[i]);
    printf("\n");

    return 0;
}
