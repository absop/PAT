#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

#define fill(lo, hi, val) memset(lo, val, (hi - lo) * sizeof lo[0])
#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }
#define MAXN 10000

struct _vector {
    int len;
    int alloc;
    int *adj;
} graph[MAXN + 1];
int temp[MAXN + 1], res[MAXN + 1], num, maxdepth;
bool visit[MAXN + 1];

void dfs(int s, int depth)
{
    if (depth >= maxdepth) {
        if (depth > maxdepth) {
            num = 0;
            maxdepth = depth;
        }
        temp[num++] = s;
    }
    visit[s] = true;
    for (int i = 0; i < graph[s].len; ++i) {
        if (!visit[graph[s].adj[i]])
            dfs(graph[s].adj[i], depth + 1);
    }
}

void addedge(int i, int j)
{
    if (graph[i].len >= graph[i].alloc) {
        graph[i].alloc += 5;
        graph[i].adj = realloc(graph[i].adj, sizeof(int) * graph[i].alloc);
    }
    graph[i].adj[graph[i].len++] = j;
}

int main()
{
    int node1, node2, N, count, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d %d", &node1, &node2);
        addedge(node1, node2);
        addedge(node2, node1);
    }

    for (int i = 1; i <= N; ++i) {
        if (!visit[i]) {
            dfs(i, 0);
            ++cnt;
        }
    }
    if (cnt == 1) {
        count = num;
        memcpy(res, temp, num * sizeof temp[0]);
        fill(visit, visit + N + 1, false);
        dfs(temp[0], 0);

        fill(visit, visit + N + 1, false);
        for (int i = 0; i < count; ++i)
            visit[res[i]] = true;
        for (int i = count - 1; i < num; ++i) {
            if (!visit[temp[i]])
                res[count++] = temp[i];
        }
        sort(res, res + count, cmp);
        for (int i = 0; i < count; ++i)
            printf("%d\n", res[i]);
    }
    else printf("Error: %d components\n", cnt);
    for (int i = 1; i <= N; ++i) {
        if (graph[i].alloc)
            free(graph[i].adj);
    }

    return 0;
}
