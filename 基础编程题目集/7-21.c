#include <stdio.h>


int main()
{
    int N, cnt = 0;
    scanf("%d", &N);

    int x2, sum, half =  N >> 1;
    for (int x = 1; (x2 = x * x) <= half; ++x) {
        for (int y = x; (sum = x2 + y * y) <= N; ++y) {
            if (sum == N) {
                printf("%d %d\n", x, y);
                cnt += 1;
            }
        }
    }
    if (!cnt)printf("No Solution\n");
}

