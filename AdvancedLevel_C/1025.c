#include <stdio.h>
#include <stdlib.h>

typedef struct _student_t {
    long long no;
    int local;
    int score;
} student_t;

student_t stu[30000];
int R[101][102], N, K, cnt, l, s;
long long no;

int cmp(const void *pa, const void *pb)
{
    student_t *p = (student_t *)pa;
    student_t *q = (student_t *)pb;
    // 这里如果使用如下注释掉的比较方式，会有两个测试点无法通过
    // return p->score == q->score
    //        ? (p->no - q->no)
    //        : (q->score - p->score);
    return p->score == q->score
           ? (p->no <= q->no ? -1 : 1)
           : (p->score > q->score ? -1 : 1);
}


int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &K);
        for (int j = 0; j < K; ++j) {
            scanf("%lld %d", &no, &s);
            stu[cnt++] = (student_t) {no, i, s};
            R[i][s]++;
            R[0][s]++;
        }
    }
    // 利用计数排序的方法确定各分数对应的排名
    for (int i = 0; i <= N; ++i) {
        for (int j = 100, t2 = 1; j >= 0; --j) {
            int t1 = t2;
            t2 = R[i][j];
            R[i][j] = R[i][j + 1] + t1;
        }
    }

    qsort(stu, cnt, sizeof(student_t), cmp);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        no = stu[i].no;
        l = stu[i].local;
        s = stu[i].score;
        printf("%013lld %d %d %d\n", no, R[0][s], l, R[l][s]);
    }

    return 0;
}
