#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define less(a, b) (a.score == b.score ? a.no <= b.no : a.score > b.score)
typedef struct _stu elem_t;
struct _stu {
    long long no;
    int local;
    int score;
} stu[30000], temp[15000];

int R[101][102], N, K, cnt, l, s;
long long no;

void merge_sort(elem_t dest[], int lo, int hi)
{
    if (hi - lo <= 1) return;

    int mi = (lo + hi) >> 1;
    merge_sort(dest, lo, mi);
    merge_sort(dest, mi, hi);

    if (less(dest[mi - 1], dest[mi])) return;

    int lt = mi - lo;
    int it = 0, ia = mi;
    memcpy(temp, &dest[lo], lt * sizeof(elem_t));

    while (it < lt && ia < hi) {
        if (less(temp[it], dest[ia]))
            dest[lo++] = temp[it++];
        else
            dest[lo++] = dest[ia++];
    }
    while (it < lt) dest[lo++] = temp[it++];
}


int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &K);
        for (int j = 0; j < K; ++j) {
            scanf("%lld %d", &no, &s);
            stu[cnt++] = (struct _stu) {no, i, s};
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

    merge_sort(stu, 0, cnt);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        no = stu[i].no;
        l = stu[i].local;
        s = stu[i].score;
        printf("%013lld %d %d %d\n", no, R[0][s], l, R[l][s]);
    }

    return 0;
}
