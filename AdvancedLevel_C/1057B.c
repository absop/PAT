#include <stdio.h>
#include <stdlib.h>
// 使用了二叉树依然超时，是因为是用来非平衡二叉树的缘故吗？
// O(n)时间复杂度的 search 的因素更大一些吧
#define MAXN 100001

typedef struct node {
    int num, cnt;
    struct node *lchild;
    struct node *rchild;
} node_t;

int stack[MAXN];
node_t *nodestk[MAXN];

void insert(node_t **proot, int num)
{
    node_t *p;
    for (; (p = *proot) != NULL; ) {
        if (p->num > num)
            proot = &p->lchild;
        else if (p->num < num)
            proot = &p->rchild;
        else
            break;
    }
    if (!p) {
        p = *proot = (node_t *)calloc(1, sizeof(node_t));
        p->num = num;
    }
    p->cnt++;
}

void delete(node_t **proot, int num)
{
    node_t *p, *q, **qq;
    for (; (p = *proot) != NULL; ) {
        if (p->num > num)
            proot = &p->lchild;
        else if (p->num < num)
            proot = &p->rchild;
        else
            break;
    }
#if 0
    p->cnt -= (p->cnt > 0);
#else
    if (p && --p->cnt == 0) {
        if (p->lchild) {
            if (p->rchild) {
                for (qq = &p->rchild; q = *qq, q->lchild; qq = &q->lchild);
                p->num = q->num;
                p->cnt = q->cnt;
                if (q->rchild)
                    *qq = q->rchild;
                p = q;
            }
            else *proot = p->lchild;
        }
        else *proot = p->rchild;
        free(p);
    }
#endif
}

void destroy(node_t *root)
{
    if (root) {
        destroy(root->lchild);
        destroy(root->rchild);
        free(root);
    }
}

int search(node_t *root, int nth)
{
    int cnt = 0, tp = -1;
    while (1) {
        if (root) {
            nodestk[++tp] = root;
            root = root->lchild;
        }
        else if (tp >= 0) {
            root = nodestk[tp--];
            cnt += root->cnt;
#if 0
            printf("->num(%d)[%d]", root->num, root->cnt);
            if (cnt >= nth) {
                printf("\n");
                return root->num;
            }
#else
            if (cnt >= nth)
                return root->num;
#endif
            root = root->rchild;
        }
    }
}


int main()
{
    int n, num, top = 0;
    char command[16];
    node_t *root = NULL;
#ifdef __TINYC__
    freopen("1057.txt", "w+", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", command);
        switch (command[1]) {
            case 'e':
            case 'o':
                if (top > 0) {
                    if (command[1] == 'o') {
                        num = stack[--top];
                        delete(&root, num);
                    }
                    else
                        num = search(root, (top + 1) / 2);
                    printf("%d\n", num);
                }
                else
                    printf("Invalid\n");
                break;
            case 'u':
                scanf("%d", &num);
                stack[top++] = num;
                insert(&root, num);
                break;
        }
    }

    destroy(root);

    return 0;
}
