#include <stdio.h>
#include <stdlib.h>

int stack[1000], v[1000];

int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j)
            scanf("%d", &v[j]);

        int top = -1, cnt = 0;
        for (int j = 1; j <= N; ++j) {
            stack[++top] = j;
            if (top >= M) break;
            for (; top >= 0 && stack[top] == v[cnt]; --top)
                cnt++;
        }
        printf(cnt == N ? "YES\n" : "NO\n");
    }

    return 0;
}
