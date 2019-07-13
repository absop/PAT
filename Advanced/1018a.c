/*
 * 第5和第7个测试点过不去，不知道为什么，
 * 也许是因为还没完全读懂题目:-)
 * 1018.c 全票通过。
 */
#include <limits.h>
#include <math.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _path {
    int cnt;
    int adj[500][3];
} __path;

int bike[501];
int dist[501] = {[0 ... 500] = INT_MAX};
int map[501][501] = {[0 ... 500] = {[0 ... 500] = INT_MAX}};
int Cmax, N, Sp, M;
int need, back;
bool visit[501];
__path path[501];

#define prev(v, i) path[v].adj[i][0]
#define rank(v, i) path[v].adj[i][1]
#define count(v, i) path[v].adj[i][2]

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
    dist[0] = 0;
    path[0].cnt = 1;

    for (int i = 0; i <= N; ++i) {
        int u = -1, mindst = INT_MAX;
        for (int j = 0; j <= N; ++j) {
            if (!visit[j] && dist[j] < mindst) {
                mindst = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v <= N; ++v) {
            if (!visit[v] && map[u][v] != INT_MAX) {
                if (dist[u] + map[u][v] > dist[v]) continue;
                if (dist[u] + map[u][v] < dist[v]) {
                    dist[v] = dist[u] + map[u][v];
                    path[v].cnt = 0;
                }
                for (int j = 0; j < path[u].cnt; ++j) {
                    int l = path[v].cnt++;
                    prev(v, l) = u;
                    rank(v, l) = j;
                    count(v, l) = count(u, j) + bike[v];
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
        int _need = 0, _back = 0;
        if (count(sp, i) < 0)
            _need = -count(sp, i);
        else if (count(sp, i) > 0)
            _back = count(sp, i);

        if (_need < need) {
            need = _need;
            back = _back;
            opt = i;
        }
        else if (_need == need && _back < back) {
            opt = i;
            back = _back;
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
}
