#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }

typedef struct _bucket {
    char *key;
    int len;
    int alloc;
    int *begin;
    int *end;
    struct _bucket *next;
} bucket_t;

#define BUCKET_SIZE 512
/* titles, authors, keywords, publishers, years */
bucket_t *hash_tables[5][BUCKET_SIZE];

#define HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))

void storebook(int ith, char *key, int len, int id)
{
    int h = 1;
    bucket_t *p, **pp;
    for (int i = 0; i < len; ++i)
        h = HASH_FUNC(h, key[i]);
    h &= (BUCKET_SIZE - 1);

    pp = &hash_tables[ith][h];
    for (p = *pp; p; p = p->next) {
        if (p->len == len && !memcmp(p->key, key, len))
            break;
    }
    if (p == NULL) {
        p = malloc(sizeof(bucket_t));
        *p = (bucket_t) {key, len, 0, 0, 0, *pp};
        *pp = p;
    }
    len = p->end - p->begin;
    if (len >= p->alloc) {
        p->alloc += 5;
        p->begin = realloc(p->begin, sizeof(int) * p->alloc);
        p->end = p->begin + len;
    }
    *p->end++ = id;
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
    int id, len;
    static char *key, lines[5][96];

    scanf("%d\n", &id);
    for (int i = 0; i < 5; ++i) {
        gets(lines[i]);
        if (i != 2) {
            len = strlen(lines[i]);
            key = strndup1(lines[i], len);
            storebook(i, key, len, id);
        }
    }
    for (char *p = lines[2], *q = p; *p; ++q) {
        if (*q == ' ' || *q == 0) {
            len = q - p;
            key = strndup1(p, len);
            storebook(2, key, len, id);
            p = q + (*q == ' ');
        }
    }
}

void querybook(int ith, char *key)
{
    int len, h = 1;
    for (len = 0; key[len]; ++len)
        h = HASH_FUNC(h, key[len]);
    h &= (BUCKET_SIZE - 1);

    for (bucket_t *p = hash_tables[ith][h]; p; p = p->next) {
        if (p->len == len && !memcmp(p->key, key, len)) {
            sort(p->begin, p->end, cmp);
            for (int i = 0; i < p->end - p->begin; ++i)
                printf("%07d\n", p->begin[i]);
            return;
        }
    }
    printf("Not Found\n");
}

int main()
{
    int N, M;
    char key[128];
    bucket_t *p, *next;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        readbook();
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int ith;
        scanf("%d: ", &ith);
        gets(key);
        printf("%d: %s\n", ith, key);
        querybook(ith - 1, key);
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < BUCKET_SIZE; ++j) {
            for (p = hash_tables[i][j]; p; p = next) {
                next = p->next;
                free(p->begin);
                free(p->key);
                free(p);
            }
        }
    }

    return 0;
}
