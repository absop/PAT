#include <stdio.h>
#include <limits.h>


#define true 1
#define false 0
#define CITY_MAX 500


int map[CITY_MAX][CITY_MAX];
int dist[CITY_MAX], pathnum[CITY_MAX];
int val[CITY_MAX], totval[CITY_MAX];
int known[CITY_MAX], path[CITY_MAX];


void dijkstra(int N, int s)
{
    for (int i = 0; i < N; ++i) {
        known[i] = false;
        dist[i] = INT_MAX;
        path[i] = -1;
        totval[i] = val[i];
    }

    dist[s] = 0;
    known[s] = true;
    pathnum[s] = 1;

    int d, u, mdist;

    for (int i = 0; i < N; ++i) {
        u = s, mdist = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (!known[j] && dist[j] < mdist) {
                mdist = dist[j];
                u = j;
            }
        }

        known[u] = true;

        for (int v = 0; v < N; ++v) {
            if (!known[v] && map[u][v] < INT_MAX) {
                d = dist[u] + map[u][v];
                if (d < dist[v]) {
                    dist[v] = d;
                    path[v] = u;
                    totval[v] += totval[u];
                    pathnum[v] = pathnum[u];
                }
                else if (d == dist[v]) {
                    pathnum[v] += pathnum[u];
                    if (totval[v] < totval[u] + val[v]) {
                        totval[v] = totval[u] + val[v];
                        path[v] = u;
                    }
                }
            }
        }
    }
}

void recursive_print_vertex(int s, int e)
{
    if (e != s) {
        recursive_print_vertex(s, path[e]);
        printf(" --> ");
    }
    printf("%d", e);

}

void printpath(int s, int e)
{
    recursive_print_vertex(s, e);
    printf("\n");
}

int main()
{
    int N, M, C1, C2;
    int c1, c2, L;

    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; ++i)
        scanf("%d", val + i);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            map[i][j] = INT_MAX;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &c1, &c2, &L);
        map[c1][c2] = L;
        map[c2][c1] = L;
    }

    dijkstra(N, C1);

    printf("%d %d\n", pathnum[C2], totval[C2]);

    // printpath(C1, C2);

    return 0;
}
