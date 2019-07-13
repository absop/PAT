#include <memory.h>
#include <stdbool.h>
#include <stdio.h>

int N, M, K;
int stack[1001][2];
bool map[1001][1001];
bool visit[1001];

#if 0
    #define PRINT_PATH(...) printf(__VA_ARGS__)
#else
    #define PRINT_PATH(...)
#endif

void dfs(int s, int i)
{
    visit[i] = true;
    PRINT_PATH("%d --> %d", s, i);
    int j = 1, top = 0;
    while (true) {
        for (; j <= N; ++j) {
            if (!visit[j] && map[i][j] == 1) {
                PRINT_PATH(" --> %d", j);
                visit[j] = true;
                stack[top][0] = i;
                stack[top][1] = j + 1;
                ++top;
                i = j;
                j = 1;
                break;
            }
        }
        // 不能更深，回溯
        if (j > N) {
            if (--top < 0) break;
            i = stack[top][0];
            j = stack[top][1];
        }
    }

    PRINT_PATH("\n");
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
                dfs(a, j);
                ++cnt;
            }
        }
        printf("%d\n", cnt - 1);
    }
}
