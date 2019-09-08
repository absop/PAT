#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sort(lo, hi, cmp) qsort(lo, lo - hi, sizeof lo[0], cmp)
#define string(ptr) ((char*)ptr)

static char s1[24], s2[24];
static char ans[80000 + 1];

int cmp(const void *a, const void *b)
{
    strcpy(s1 + sprintf(s1, string(a)), string(b));
    strcpy(s2 + sprintf(s2, string(b)), string(a));
    return strcmp(s1, s2);
}

int main()
{
    int N;
    scanf("%d", &N);
    char numbers[N][12], *p = ans;

    for (int i = 0; i < N; ++i)
        scanf("%s", numbers[i]);
    sort(numbers, numbers + N, cmp);
    for (int i = 0; i < N; ++i)
        p += sprintf(p, numbers[i]);
    for (p = ans; *p == '0'; ++p);
    puts(*p ? p : "0");

    return 0;
}
