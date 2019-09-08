#include <stdio.h>
#include <stdlib.h>

typedef struct _node *btree;
typedef struct _node {
    int data;
    btree lc;
    btree rc;
} node_t;
btree queue[30];
int top, vqueue[30], in[30], post[30];


btree new(int data)
{
    btree t = (btree)malloc(sizeof(node_t));
    t->lc = t->rc = NULL;
    t->data = data;
    return t;
}

void build(btree *t, int lo, int hi, int root)
{
    if (lo > hi) return;

    *t = new(post[root]);
    int i = lo - 1;
    while (in[++i] != post[root]);

    build(&(*t)->lc, lo, i - 1, root - 1 - hi + i);
    build(&(*t)->rc, i + 1, hi, root - 1);
}

void preorder(btree t, void visit(void *))
{
    if (t) {
        visit(t);
        preorder(t->lc, visit);
        preorder(t->rc, visit);
    }
}

void inorder(btree t, void visit(void *))
{
    if (t) {
        inorder(t->lc, visit);
        visit(t);
        inorder(t->rc, visit);
    }
}

void postorder(btree t, void visit(void *))
{
    if (t) {
        postorder(t->lc, visit);
        postorder(t->rc, visit);
        visit(t);
    }
}

void levelorder(btree t, void visit(void *))
{
    int head, tail;
    head = tail = 0;
    queue[tail++] = t;
    while (head < tail) {
        t = queue[head++];
        if (t->lc) queue[tail++] = t->lc;
        if (t->rc) queue[tail++] = t->rc;
        visit(t);
    }
}

void visit(void *t) { vqueue[top++] = ((btree)t)->data; }
void travprint(void order(btree t, void visit(void *)), btree t)
{
    top = 0;
    order(t, visit);
    printf("%d", vqueue[0]);
    for (int i = 1; i < top; ++i)
        printf(" %d", vqueue[i]);
    printf("\n");
}


int main()
{
    int N;
    btree t = NULL;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < N; ++i) scanf("%d", &in[i]);

    build(&t, 0, N - 1, N - 1);
    // travprint(preorder, t);
    // travprint(inorder, t);
    // travprint(postorder, t);
    travprint(levelorder, t);

    postorder(t, free);

    return 0;
}
