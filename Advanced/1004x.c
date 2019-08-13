#include <stdio.h>
#include <stdlib.h>


#define MAXN 100
#define MAXM 100

int table[100][100];
int count[100], Nchild[100];
int Nlevel;


void dfs(x)
{
    int level = 0;
    int head = 0, tail = 0, rightest;
    int queue[10000];

    rightest = x;
    do {
        if (Nchild[x] == 0)
            count[level]++;

        for (int i = 0; i < Nchild[x]; ++i)
            queue[tail++] = table[x][i];

        if (x == rightest) {
            level++;
            rightest = queue[tail - 1];
        }

        x = queue[head++];
    }
    while (head <= tail);

    Nlevel = level;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int ID, k;
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &ID, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &table[ID][Nchild[ID]++]);
        }
    }

    dfs(1);

    printf("%d", count[0]);
    for (int i = 1; i < Nlevel; ++i)
        printf(" %d", count[i]);
    printf("\n");

    return 0;
}
