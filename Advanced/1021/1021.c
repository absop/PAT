#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

#define new(len, type) (type *)malloc((len) * sizeof(type))
#define fill(name, len, type) memset(name, 0, (len) * sizeof(type))
#define newfill(name, len, type) name = new(len, type); fill(name, len, type)

struct _node {
    int data;
    struct _node *next;
};

struct _adj {
    struct _node *head;
    struct _node *tail;
} *adj;

int *temp, *res, N, num, maxdepth;
bool *visit;

void dfs(int s, int d)
{
    if (d >= maxdepth) {
        if (d > maxdepth) {
            num = 0;
            maxdepth = d;
        }
        temp[num++] = s;
    }
    visit[s] = true;
    // 全局变量慎用，此处如果p作为全局变量，会出现内存错误
    for (struct _node *p = adj[s].head; p; p = p->next) {
        if (!visit[p->data])
            dfs(p->data, d + 1);
    }
}

int cmp(const void *i, const void *j) { return *((int *)i) - *((int *)j); }
void add_edge(int i, int j)
{
    struct _node *p = new(1, struct _node);
    p->data = j;
    p->next = NULL;
    if (adj[i].head != NULL)
        adj[i].tail->next = p;
    else
        adj[i].head = p;
    adj[i].tail = p;
}

void read_edge(int n)
{
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
}
void init(int n)
{
    newfill(res, n, int);
    newfill(temp, n, int);
    newfill(visit, n, bool);
    newfill(adj, n, struct _adj);
}
void gc()
{
    struct _node *q, *p;
    for (int i = 1; i <= N; ++i) {
        for (p = adj[i].head; p;) {
            q = p->next;
            free(p);
            p = q;
        }
    }
    free(adj);
    free(res);
    free(temp);
    free(visit);
}

int main()
{
    int cnt = 0;
    scanf("%d", &N);
    init(N + 1);
    read_edge(N - 1);

    dfs(1, 0); ++cnt;
    for (int i = 2; i <= N; ++i) {
        if (!visit[i]) {
            dfs(i, 0);
            ++cnt;
        }
    }
    if (cnt > 1)
        printf("Error: %d components\n", cnt);
    else {
        int count = num;
        for (int i = 0; i < num; ++i)
            res[i] = temp[i];

        maxdepth = -1;
        fill(visit, N + 1, bool);
        dfs(temp[0], 0);

        fill(visit, N + 1, bool);
        for (int i = 0; i < count; ++i)
            visit[res[i]] = true;
        for (int i = 0; i < num; ++i) {
            if (!visit[temp[i]])
                res[count++] = temp[i];
        }

        qsort(res, count, sizeof(int), cmp);

        for (int i = 0; i < count; ++i)
            printf("%d\n", res[i]);

        gc();
    }

    return 0;
}
