#include <stdio.h>

int dist[100005];
#define min(a, b) ((b) < (a) ? (b) : (a))
#define abs(x) ((x) < 0 ? -(x): (x))
#define dist(i, j) abs(dist[j] - dist[i])

int main()
{
    int N, M, d, b, e1, e2;
    scanf("%d", &N);
    for (int i = 2; i <= N + 1; ++i) {
        scanf("%d", &dist[i]);
        dist[i] += dist[i - 1];
    }

    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &e1, &e2);
        d = dist(e1, e2);
        b = dist[N + 1] - d;
        printf("%d\n", min(d, b));
    }

}
