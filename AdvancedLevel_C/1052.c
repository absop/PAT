#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
    int addr;
    int key;
    int next;
} node_t;

node_t map[100000];

#define key(ptr) (((node_t*)ptr)->key)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return key(a) - key(b); }

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
        map[addr] = (node_t) {addr, key, next};
    }

    node_t *list = (node_t *)malloc(sizeof(node_t) * N);
    for (; head != -1; head = map[head].next)
        list[len++] = map[head];

    qsort(list, len, sizeof(node_t), cmp);
    printf("%d %05d\n", len, list->addr);
    for (node_t *p = list; p < &list[len - 1]; ++p)
        printf("%05d %d %05d\n", p->addr, p->key, (p + 1)->addr);
    printf("%05d %d -1\n", list[len - 1].addr, list[len - 1].key);

    free(list);

    return 0;
}
