#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _edge *pedge;
typedef struct _vertex *pvertex;

#define true 1
#define false 0

struct _edge {
    int city;
    int dist;
    struct _edge *next;
};

struct _vertex {
    int val;
    pedge tail;
    pedge head;

    int pathnum;
    int totval;
    int path;
};

void dijkstra(pvertex V_T, int N, int s)
{
    pedge e;
    int u, v, mdist, d;
    int known[N], dist[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INT_MAX;
        known[i] = false;
        V_T[i].path = -1;
        V_T[i].pathnum = 0;
        V_T[i].totval = V_T[i].val;
    }

    dist[s] = 0;
    known[s] = true;
    V_T[s].pathnum = 1;

    for (int i = 0; i < N; ++i) {
        u = s; mdist = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (!known[j] && dist[j] < mdist) {
                u = j;
                mdist = dist[j];
            }
        }
        known[u] = true;

        for (e = V_T[u].head; e != NULL; e = e->next) {
            v = e->city;
            d = dist[u] + e->dist;
            if (known[v] || d > dist[v])
                continue;

            if (d < dist[v]) {
                dist[v] = d;
                V_T[v].path = u;
                V_T[v].totval += V_T[u].totval;
                V_T[v].pathnum = V_T[u].pathnum;
            }
            else {  // d == dist[v]
                V_T[v].pathnum += V_T[u].pathnum;
                if (V_T[v].totval < V_T[u].totval + V_T[v].val) {
                    V_T[v].totval = V_T[u].totval + V_T[v].val;
                    V_T[v].path = u;
                }
            }
        }
    }
}

void recursive_print_vertex(pvertex V_T, int s, int e)
{
    if (e != s) {
        recursive_print_vertex(V_T, s, V_T[e].path);
        printf(" --> ");
    }
    printf("%d", e);

}

void printpath(pvertex V_T, int s, int e)
{
    recursive_print_vertex(V_T, s, e);
    printf("\n");
}

#define add_edge(a, b, l)  {                    \
        e = (pedge)malloc(sizeof(struct _edge));\
        e->city = b;                            \
        e->dist = l;                            \
        e->next = NULL;                         \
        if (V_T[a].head == NULL)                \
            V_T[a].head = e;                    \
        else                                    \
            V_T[a].tail->next = e;              \
        V_T[a].tail = e;                        \
    }

int main()
{
    int N, M, C1, C2;
    int val, c1, c2, L;
    pedge e, ee;
    pvertex V_T;

    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    V_T = (pvertex)malloc(N * sizeof(struct _vertex));

    for (int i = 0; i < N; ++i) {
        scanf("%d", &val);
        V_T[i].val = val;
        V_T[i].head = NULL;
    }

    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &c1, &c2, &L);
        add_edge(c1, c2, L);
        add_edge(c2, c1, L);
    }

    dijkstra(V_T, N, C1);
    printf("%d %d\n", V_T[C2].pathnum, V_T[C2].totval);
    printpath(V_T, C1, C2);

    for (int i = 0; i < N; ++i) {
        for (e = V_T[i].head; e != NULL;) {
            ee = e->next;
            free(e);
            e = ee;
        }
    }
    free(V_T);

    return 0;
}
