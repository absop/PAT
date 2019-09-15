#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H(c) (c - 'A')
#define D(c) (c - '0')
#define hash(s) (((H(s[0]) * 26 + H(s[1])) * 26 + H(s[2])) * 10 + D(s[3]))
#define sort(lo, hi, cmp) qsort(lo, hi - lo, sizeof lo[0], cmp)
#define iptr(ptr) ((int*)ptr)
#define cvptr const void *
int cmp(cvptr a, cvptr b) { return *iptr(a) - *iptr(b); }

struct _vector {
    int len;
    int alloc;
    int *data;
} v[2501];


int main()
{
    int N, K, h, ncourse;
    char name[8];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s %d", name, &ncourse);
        for (int j = 0; j < ncourse; ++j) {
            scanf("%d", &h);
            if (v[h].len >= v[h].alloc) {
                v[h].alloc += 5;
                v[h].data = realloc(v[h].data, sizeof(int) * v[h].alloc);
            }
            v[h].data[v[h].len++] = hash(name);
        }
    }
    for (int i = 1; i <= K; ++i) {
        printf("%d %d\n", i, v[i].len);
        sort(v[i].data, v[i].data + v[i].len, cmp);
        for (int j = 0; j < v[i].len; ++j) {
            h = v[i].data[j];
            name[3] = '0' + h % 10; h /= 10;
            name[2] = 'A' + h % 26; h /= 26;
            name[1] = 'A' + h % 26; h /= 26;
            name[0] = 'A' + h % 26;
            name[4] = 0;
            puts(name);
        }
    }
    for (int i = 1; i <= K; ++i) {
        if (v[i].alloc)
            free(v[i].data);
    }

    return 0;
}
