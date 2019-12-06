#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 512
#define HASH(x) ((x) + ((x) << 5) + ((x) >> 27))

typedef struct _bucket {
    int value;
    struct _bucket *next;
} bucket_t;

typedef struct _set {
    int length, nbucket;
    bucket_t *table[HASH_TABLE_SIZE];
} set_t;

set_t sets[51];

bucket_t **find(set_t *set, int x)
{
    int hash = HASH(x) & (HASH_TABLE_SIZE - 1);
    bucket_t **pp = &set->table[hash];
    for (; *pp; pp = &(*pp)->next) {
        if ((*pp)->value == x)
            break;
    }
    return pp;
}

void add(set_t *set, int x)
{
    bucket_t **pp = find(set, x);
    if (!*pp) {
        (*pp) = malloc(sizeof (bucket_t));
        (*pp)->value = x;
        (*pp)->next = NULL;
        set->length++;
    }
}

void clear(set_t *set)
{
    bucket_t *p, *q;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        for (p = set->table[i]; p; p = q) {
            q = p->next;
            free(p);
        }
    }
}

double similarity(set_t *s1, set_t *s2)
{
    bucket_t *p;
    int nc = 0, nt = s1->length;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        for (p = s2->table[i]; p; p = p->next)
            if (*find(s1, p->value))
                ++nc;
            else
                ++nt;
    }
    return nc / (double)nt;
}


int main()
{
    int n, k, x, i1, i2, nset;

    scanf("%d", &nset);
    for (int i = 1; i <= nset; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x);
            add(&sets[i], x);
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &i1, &i2);
        printf("%.1lf%%\n", 100 * similarity(&sets[i1], &sets[i2]));
    }

    for (int i = 1; i <= nset; ++i)
        clear(&sets[i]);

    return 0;
}
