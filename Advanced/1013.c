#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

bool visit[1001];
int map[1001][1001];
int N, M, K;


void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= N; ++i) {
        if (!visit[i] && map[node][i] == 1)
            dfs(i);
    }
}

int main()
{
    int a, b;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &a, &b);
        map[a][b] = map[b][a] = 1;
    }

    for (int i = 0; i < K; ++i) {
        memset(visit, 0, 1001);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= N; ++j) {
            if (!visit[j]) {
                dfs(j);
                ++cnt;
            }
        }
        printf("%d\n", cnt - 1);
    }
}
