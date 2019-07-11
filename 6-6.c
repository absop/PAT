#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i = 0; i < N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */

int FactorialSum( List L )
{
    int Fac_Table[13] = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320,
        362880,
        3628800,
        39916800,
        479001600
    };
    int SUM = 0;
    while (L != NULL) {
        SUM += Fac_Table[L->Data];
        L = L->Next;
    }
    return SUM;
}