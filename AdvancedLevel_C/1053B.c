#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct _node {
    int weigth;
    int nchild;
    int *child;
} node_t;

typedef struct _vector {
    int len;
    int alloc;
    int *data;
} vector_t;

int npath;
node_t nodes[100];
vector_t *paths[100];

#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define vptr(ptr) (*((vector_t**)ptr))
#define cvptr const void *
int cmp(cvptr a, cvptr b)
{
    int i = 0, cond;
    for (; i < vptr(a)->len && i < vptr(b)->len; ++i) {
        cond = vptr(b)->data[i] - vptr(a)->data[i];
        if (cond) return cond;
    }
    return i < vptr(a)->len ? -1 : i < vptr(b)->len ? 1 : 0;
}

void addnode(vector_t *v, int node)
{
    if (v->len >= v->alloc) {
        v->alloc += 5;
        v->data = realloc(v->data, v->alloc * sizeof (int));
    }
    v->data[v->len++] = node;
}

vector_t *copy(vector_t *v)
{
    vector_t *vv = malloc(sizeof (vector_t));
    vv->len = v->len;
    vv->alloc = v->alloc;
    vv->data = malloc(vv->alloc * sizeof (int));
    memcpy(vv->data, v->data, v->len * sizeof (int));
    return vv;
}

void dfs(int s, vector_t *v, int sum, int S)
{
    addnode(v, nodes[s].weigth);
    sum += nodes[s].weigth;
    if (nodes[s].nchild && sum < S) {
        for (int i = 0; i < nodes[s].nchild; ++i)
            dfs(nodes[s].child[i], copy(v), sum, S);
    }
    else if (!nodes[s].nchild && sum == S)
        paths[npath++] = v;
    else {
        free(v->data);
        free(v);
    }
}


int main()
{
    int N, M, S, id;
    const char *fmts[2] = {"%d", " %d"};
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N; ++i)
        scanf("%d", &nodes[i].weigth);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &id);
        scanf("%d", &nodes[id].nchild);
        nodes[id].child = malloc(nodes[id].nchild * sizeof (int));
        for (int j = 0; j < nodes[id].nchild; ++j)
            scanf("%d", &nodes[id].child[j]);
    }
    vector_t *v = calloc(sizeof (vector_t), 1);
    dfs(0, v, 0, S);

    sort(paths, paths + npath, cmp);
    for (int i = 0; i < npath; ++i) {
        for (int j = 0; j < paths[i]->len; ++j)
            printf(fmts[!!j], paths[i]->data[j]);
        printf("\n");
    }

    for (int i = 0; i < 100; ++i) {
        if (nodes[i].child)
            free(nodes[i].child);
        if (i < npath) {
            free(paths[i]->data);
            free(paths[i]);
        }
    }

    return 0;
}
