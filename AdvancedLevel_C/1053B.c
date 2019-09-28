#include <stdio.h>
#include <stdlib.h>

struct _node {
    int weigth;
    int nchild;
    int *child;
} v[100];

int N, M, S, id;
int stack[100], top;
const char *fmts[2] = {"%d", " %d"};

#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return v[*iptr(b)].weigth - v[*iptr(a)].weigth; }


void dfs(int s, int sum)
{
    if (v[s].nchild && sum < S)
        for (int i = 0; i < v[s].nchild; ++i) {
            id = v[s].child[i];
            stack[top] = v[id].weigth;
            dfs(id, sum + stack[top++]);
            top--;
        }
    else if (!v[s].nchild && sum == S) {
        for (int i = 0; i < top; ++i)
            printf(fmts[!!i], stack[i]);
        printf("\n");
    }
}


int main()
{
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i].weigth);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &id);
        scanf("%d", &v[id].nchild);
        v[id].child = malloc(v[id].nchild * sizeof (int));
        for (int j = 0; j < v[id].nchild; ++j)
            scanf("%d", &v[id].child[j]);
        sort(v[id].child, v[id].child + v[id].nchild, cmp);
    }
    stack[top++] = v[0].weigth;
    dfs(0, v[0].weigth);

    for (int i = 0; i < 100; ++i) {
        if (v[i].child)
            free(v[i].child);
    }

    return 0;
}
