#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int *)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }

typedef struct _node {
    char *key;
    struct _node *lchild;
    struct _node *rchild;
    int len;
    int alloc;
    int *data;
} node_t;

/* titles, authors, keywords, publishers, years */
node_t *search_trees[5];

void storebook(int ith, char *key, int id)
{
    int cond;
    node_t *p, **pp;

    pp = &search_trees[ith];
    for (p = *pp; p != NULL;) {
        if ((cond = strcmp(p->key, key)) == 0)
            break;
        else if (cond < 0)
            p = *(pp = &p->lchild);
        else
            p = *(pp = &p->rchild);
    }
    if (p == NULL) {
        p = calloc(sizeof(node_t), 1);
        p->key = key;
        *pp = p;
    }
    if (p->len >= p->alloc) {
        p->alloc += 5;
        p->data = realloc(p->data, sizeof(int) * p->alloc);
    }
    p->data[p->len++] = id;
}

char *strndup1(char *s, int len)
{
    char *ss = malloc(len + 1);
    memcpy(ss, s, len);
    ss[len] = 0;
    return ss;
}

void readbook()
{
    int id;
    static char lines[5][96];

    scanf("%d\n", &id);
    for (int i = 0; i < 5; ++i) {
        gets(lines[i]);
        if (i != 2)
            storebook(i, strdup(lines[i]), id);
    }
    for (char *p = lines[2], *q = p; *p; ++q) {
        if (*q == ' ' || *q == 0) {
            storebook(2, strndup1(p, q - p), id);
            p = q + (*q == ' ');
        }
    }
}

void querybook(int ith, char *key)
{
    for (node_t *p = search_trees[ith]; p != NULL;) {
        int cond = strcmp(p->key, key);
        if (cond < 0) p = p->lchild;
        else if (cond > 0) p = p->rchild;
        else {
            sort(p->data, p->data + p->len, cmp);
            for (int i = 0; i < p->len; ++i)
                printf("%07d\n", p->data[i]);
            return;
        }
    }

    printf("Not Found\n");
}

void gc(node_t *p)
{
    if (p) {
        free(p->key);
        gc(p->lchild);
        gc(p->rchild);
        free(p->data);
        free(p);
    }
}

int main()
{
    int N, M;
    char key[128];

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) readbook();
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int ith;
        scanf("%d: ", &ith);
        gets(key);
        printf("%d: %s\n", ith, key);
        querybook(ith - 1, key);
    }

    for (int i = 0; i < 5; ++i)
        gc(search_trees[i]);

    return 0;
}
