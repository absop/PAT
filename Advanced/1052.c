#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct _node *pnode;
typedef struct _node {
    int addr;
    int key;
    int next;
} tnode;

static __inline int cmp(const void *a, const void *b)
{
    int ka = ((struct _node *)a)->key;
    int kb = ((struct _node *)b)->key;
    return (ka - kb);
}

tnode LT[MAXN];

int main()
{
    int N, len, head, addr, key, next;

    scanf("%d %d", &N, &head);

    if (N == 0 || head == -1) {
        printf("0 -1\n");
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &addr, &key, &next);
        LT[addr] = (tnode){
            addr: addr,
            key: key,
            next: next
        };
    }

    pnode p, list = (tnode *)malloc(sizeof(tnode) * N);

    while (head != -1) {
        list[len++] = LT[head];
        head = LT[head].next;
    }

    qsort(list, len, sizeof(tnode), cmp);

    printf("%d %05d\n", len, list->addr);
    for (p = list; p < list + len - 1; ++p) {
        addr = p->addr;
        key = p->key;
        next = (p + 1)->addr;
        printf("%05d %d %05d\n", addr, key, next);
    }
    printf("%05d %d -1\n", p->addr, p->key);

    free(list);

    return 0;
}
