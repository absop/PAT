#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H(c) (c - 'A')
#define D(c) (c - '0')
#define hash(s) (((H(s[0]) * 26 + H(s[1])) * 26 + H(s[2])) * 10 + D(s[3]))
#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }

struct _vector {
    int len;
    int alloc;
    int *data;
} v[175761];


void addcourse(char *name, int course)
{
    int i = hash(name);
    if (v[i].len >= v[i].alloc) {
        v[i].alloc += 5;
        v[i].data = realloc(v[i].data, sizeof(int) * v[i].alloc);
    }
    v[i].data[v[i].len++] = course;
}

void querycourse(char *name)
{
    int i = hash(name);
    sort(v[i].data, v[i].data + v[i].len, cmp);
    printf("%s %d", name, v[i].len);
    for (int j = 0; j < v[i].len; ++j)
        printf(" %d", v[i].data[j]);
    printf("\n");
}

int main()
{
    int N, K, idcourse, nname;
    char name[5];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d %d", &idcourse, &nname);
        for (int j = 0; j < nname; ++j) {
            scanf("%s", name);
            addcourse(name, idcourse);
        }
    }
    for (int i = 0; i < N; ++i) {
        scanf("%s", name);
        querycourse(name);
    }
    for (int i = 0; i < 175761; ++i) {
        if (v[i].alloc)
            free(v[i].data);
    }

    return 0;
}
