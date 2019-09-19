#include <stdio.h>

int pos = 0, cnt = 0, N;
int res[31];

void dfs(int x, int sum)
{
    if (sum < N) {
        for (sum += x; sum <= N; x++, sum++) {
            res[pos++] = x;
            dfs(x, sum);
            pos--;
        }
    }
    else {
        printf("%d=%d", N, res[0]);
        for (int i = 1; i < pos; i++)
            printf("+%d", res[i]);
        putchar(++cnt % 4 && pos > 1 ? ';' : '\n');
    }
}


int main()
{
    scanf("%d", &N);
    dfs(1, 0);

    return 0;
}
