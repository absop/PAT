#include <limits.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _path {
    int cnt;
    int adj[500][4];
} path[501];

int bike[501];
int dist[501] = {[0 ... 500] = INT_MAX};
int map[501][501] = {[0 ... 500] = {[0 ... 500] = INT_MAX}};
int Cmax, N, Sp, M;
int need, back;
bool visit[501];

#define need(v, i) path[v].adj[i][0]
#define back(v, i) path[v].adj[i][1]
#define prev(v, i) path[v].adj[i][2]
#define rank(v, i) path[v].adj[i][3]

void recursive_print_path(int v, int i)
{
    if (v != 0) {
        recursive_print_path(prev(v, i), rank(v, i));
        printf("->");
    }
    printf("%d", v);
}

void dijkstra()
{
    int u, v, mindst;
    dist[0] = 0;
    path[0].cnt = 1;
    for (int i = 0; i < N; ++i) {
        for (mindst = INT_MAX, v = 0; v <= N; ++v) {
            if (!visit[v] && dist[v] < mindst) {
                mindst = dist[v];
                u = v;
            }
        }
        for (visit[u] = true, v = 0; v <= N; ++v) {
            if (visit[v] || map[u][v] == INT_MAX) continue;
            if (dist[u] + map[u][v] > dist[v]) continue;
            if (dist[u] + map[u][v] < dist[v]) {
                dist[v] = dist[u] + map[u][v];
                path[v].cnt = 0;
            }
            for (int j = 0; j < path[u].cnt; ++j) {
                int l = path[v].cnt++;
                prev(v, l) = u;
                rank(v, l) = j;
                back(v, l) = back(u, j);
                need(v, l) = need(u, j);
                back(v, l) += bike[v];
                if (back(v, l) < 0) {
                    need(v, l) -= back(v, l);
                    back(v, l) = 0;
                }
            }
        }
    }
}

int select_optimal_path(int sp)
{
    int opt = -1;
    need = back = INT_MAX;
    for (int i = 0; i < path[sp].cnt; ++i) {
        if (need(sp, i) < need) {
            opt = i;
            need = need(sp, i);
            back = back(sp, i);
        }
        else if (need(sp, i) == need && back(sp, i) < back) {
            opt = i;
            back = back(sp, i);
        }
    }
    return opt;
}


int main()
{
    scanf("%d%d%d%d", &Cmax, &N, &Sp, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &bike[i]);
        bike[i] -= Cmax / 2;
    }
    int u, v, weight;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &u, &v, &weight);
        map[u][v] = map[v][u] = weight;
    }

    dijkstra(0);
    int opt = select_optimal_path(Sp);

    printf("%d ", need);
    recursive_print_path(Sp, opt);
    printf(" %d\n", back);

    return 0;
}
