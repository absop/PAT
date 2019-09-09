#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int prev[500] = {[0 ... 499] = -1};
int dist[500] = {[0 ... 499] = INT_MAX};
int map[500][500] = {[0 ... 499] = {[0 ... 499] = INT_MAX}};
int pathnum[500], val[500], totval[500];
bool visit[500];

void dijkstra(int N, int s)
{
    int d, u, v, mdist;
    dist[s] = 0;
    pathnum[s] = 1;
    totval[s] = val[s];
    for (int i = 0; i < N - 1; ++i) {
        for (mdist = INT_MAX, v = 0; v < N; ++v) {
            if (!visit[v] && dist[v] < mdist) {
                mdist = dist[v];
                u = v;
            }
        }
        for (visit[u] = true, v = 0; v < N; ++v) {
            if (visit[v] || map[u][v] == INT_MAX)
                continue;
            d = dist[u] + map[u][v];
            if (d > dist[v]) continue;
            if (d < dist[v]) {
                dist[v] = d;
                prev[v] = u; // 这句注释之后能通过测试
                pathnum[v] = 0;
            }
            pathnum[v] += pathnum[u];
            if (totval[v] < totval[u] + val[v]) {
                totval[v] = totval[u] + val[v];
                prev[v] = u;
            }
        }
    }
}

void recprintpath(int s, int e)
{
    if (e != s) {
        recprintpath(s, prev[e]);
        printf(" --> ");
    }
    printf("%d", e);
}

void printpath(int s, int e) { recprintpath(s, e); printf("\n"); }

int main()
{
    int N, M, C1, C2;
    int c1, c2, L;

    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; ++i) scanf("%d", &val[i]);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &c1, &c2, &L);
        map[c1][c2] = map[c2][c1] = L;
    }
    dijkstra(N, C1);
    printf("%d %d\n", pathnum[C2], totval[C2]);

    return 0;
}
