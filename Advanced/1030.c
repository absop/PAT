#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <limits.h>

#define dist(u, v) map[u][v][0]
#define cost(u, v) map[u][v][1]
#define prev(u, v) path[u][v][0]
#define rank(u, v) path[u][v][1]
#define total_cost(u, v) path[u][v][2]

int map[500][500][2] = {[0 ... 499] = {[0 ... 499] = {INT_MAX}}};
int path[500][500][3], number[500], dist[500] = {[0 ... 499] = INT_MAX};
bool visit[499];


void dijkstra(int start, int N)
{
    dist[start] = 0;
    number[start] = 1;

    for (int i = 0; i < N; ++i) {
        int u = -1, mindst = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && dist[j] < mindst) {
                mindst = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!visit[v] && dist(u, v) != INT_MAX) {
                if (dist[u] + dist(u, v) > dist[v]) continue;
                if (dist[u] + dist(u, v) < dist[v]) {
                    dist[v] = dist[u] + dist(u, v);
                    number[v] = 0;
                }
                for (int j = 0; j < number[u]; ++j) {
                    int r = number[v]++;
                    prev(v, r) = u;
                    rank(v, r) = j;
                    total_cost(v, r) = total_cost(u, j) + cost(u, v);
                }
            }
        }
    }
}

void recursive_print_path(int s, int d, int i)
{
    if (d != s) {
        recursive_print_path(s, prev(d, i), rank(d, i));
        printf(" ");
    }
    printf("%d", d);
}


int main()
{
    int N, M, S, D;
    int c1, c2, d, c;
    scanf("%d %d %d %d", &N, &M, &S, &D);

    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        dist(c1, c2) = dist(c2, c1) = d;
        cost(c1, c2) = cost(c2, c1) = c;
    }

    dijkstra(S, N);

    int optimal_cost = INT_MAX, optimal_rank = -1;
    for (int i = 0; i < number[D]; ++i) {
        if (total_cost(D, i) < optimal_cost) {
            optimal_cost = total_cost(D, i);
            optimal_rank = i;
        }
    }

    recursive_print_path(S, D, optimal_rank);
    printf(" %d %d", dist[D], optimal_cost);

    return 0;
}
