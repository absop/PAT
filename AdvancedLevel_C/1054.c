#include <stdio.h>
#include <stdlib.h>

typedef struct _bucket {
    int value;
    int count;
    struct _bucket *next;
} bucket_t;

#define HASH_TABLE_SIZE 1024
#define HASH(x) ((x) + ((x) << 5) + ((x) >> 27))
bucket_t *hash_tables[HASH_TABLE_SIZE];

int count(int x)
{
    int h = HASH(x) & (HASH_TABLE_SIZE - 1);
    bucket_t *p, **pp;
    pp = &hash_tables[h];
    for (p = *pp; p; p = p->next) {
        if (p->value == x)
            break;
    }
    if (!p) {
        p = malloc(sizeof (bucket_t));
        p->value = x;
        p->count = 0;
        p->next = *pp;
        *pp = p;
    }
    p->count++;

    return p->count;
}

int main()
{
    int M, N, pro, half, x;
    scanf("%d %d", &M, &N);
    pro = M * N, half = pro / 2;
    for (int i = 0; i < pro; ++i) {
        scanf("%d", &x);
        if (count(x) > half) {
            printf("%d\n", x);
            break;
        }
    }

    bucket_t *next, *p;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        for (p = hash_tables[i]; p; p = next) {
            next = p->next;
            free(p);
        }
    }

    return 0;
}
