#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *prev;
    struct _node *next;
} node_t;

typedef struct _set {
    int count;
    node_t *root;
} set_t;

set_t sets[51];
node_t *node_stack[1000];

node_t **find(set_t *set, int x)
{
    node_t *p, **pp = &set->root;
    for (; (p = *pp) && p->value != x; ) {
        if (x < p->value)
            pp = &p->prev;
        else
            pp = &p->next;
    }
    return pp;
}

void add(set_t *set, int x)
{
    node_t **pp = find(set, x);
    if (!*pp) {
        (*pp) = malloc(sizeof (node_t));
        (*pp)->value = x;
        (*pp)->prev = (*pp)->next = NULL;
        set->count++;
    }
}

void destroy_tree(node_t *node)
{
    if (node) {
        destroy_tree(node->prev);
        destroy_tree(node->next);
        free(node);
    }
}

void clear(set_t *set)
{
    destroy_tree(set->root);
    set->root = NULL;
    set->count = 0;
}

double similarity(set_t *s1, set_t *s2)
{
    node_t *p = s2->root;
    int nc = 0, nt = s1->count;
    for (int top = -1; p || top >= 0;) {
        if (p) {
            node_stack[++top] = p;
            p = p->prev;
        }
        else {
            p = node_stack[top--];
            if (*find(s1, p->value))
                ++nc;
            else
                ++nt;
            p = p->next;
        }
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
