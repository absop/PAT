#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _stu {
    int no;
    char name[10];
    short grade;
} stu[100000];

int N, C, o_o;

#define no(ptr) ((struct _stu*)ptr)->no
#define name(ptr) ((struct _stu*)ptr)->name
#define grade(ptr) ((struct _stu*)ptr)->grade
#define cmpx(a, b, x, cmp) (o_o = cmp(x(a), x(b)), o_o == 0? cmp1(a, b): o_o)
#define cmpi(x, y) ((x) - (y))
#define cvptr const void *

int cmp1(cvptr a, cvptr b) { return cmpi(no(a), no(b)); }
int cmp2(cvptr a, cvptr b) { return cmpx(a, b, name, strcmp); }
int cmp3(cvptr a, cvptr b) { return cmpx(a, b, grade, cmpi); }

int (*cmp[4])(cvptr, cvptr) = { 0, cmp1, cmp2, cmp3 };

int main()
{
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; ++i)
        scanf("%d %s %d", &stu[i].no, stu[i].name, &stu[i].grade);

    qsort(stu, N, sizeof(stu[0]), cmp[C]);

    for (int i = 0; i < N; ++i)
        printf("%06d %s %d\n", stu[i].no, stu[i].name, stu[i].grade);

    return 0;
}
