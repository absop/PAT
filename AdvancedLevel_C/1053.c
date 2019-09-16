#include <stdio.h>
#include <stdlib.h>

struct _node {
    int weigth;
    int nchild;
    int *child;
} v[100];

#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return v[*iptr(b)].weigth - v[*iptr(a)].weigth; }

int main()
{
    int N, M, S, id;
    const char *fmts[2] = {"%d", " %d"};
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
    int index[100] = {0};
    int stack[100], top = 0;
    int child, sum = v[0].weigth;
    for (stack[top++] = 0; top > 0;) {
        id = stack[top - 1];
        if (index[id] < v[id].nchild &&
            v[id].nchild && sum < S) {
            child = v[id].child[index[id]++];
            stack[top++] = child;
            sum += v[child].weigth;
        }
        else {
            if (!v[id].nchild && sum == S) {
                for (int i = 0; i < top; ++i)
                    printf(fmts[!!i], v[stack[i]].weigth);
                printf("\n");
            }
            sum -= v[stack[--top]].weigth;
        }
    }

    for (int i = 0; i < 100; ++i) {
        if (v[i].child)
            free(v[i].child);
    }

    return 0;
}
