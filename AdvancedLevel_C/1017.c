#include <stdio.h>
#include <stdlib.h>

typedef struct _customer_t {
    int atime;  // arriving time by second
    int ptime;  // processing time by second
} customer_t;
int windows[100] = {[0 ... 99] = 8 * 3600};

#define cvptr const void *
#define patime(ptr) (((customer_t*)ptr)->atime)
int cmp(cvptr a, cvptr b) { return patime(a) - patime(b); }

#define atime(i) customer[i].atime  // arriving time of ith customer
#define ptime(i) customer[i].ptime  // processing time of ith customer
#if 0
#define printtime(t) \
    printf("%02d:%02d:%02d", (t) / 3600, ((t) / 60) % 60, (t) % 60)

#define showalltime()                   \
    for (int i = 0; i < N; ++i) {       \
        printf("%d ", i);               \
        printtime(atime(i));            \
        printf(" %d\n", ptime(i) / 60); \
    }
#define showtime(i, w)                            \
    do {                                          \
        printf("%d served at window %d: ", i, w); \
        printtime(windows[w] - ptime(i));         \
        printf(" - ");                            \
        printtime(windows[w]);                    \
        putchar('\n');                            \
    } while (0)
#else
#define showalltime()
#define showtime(i, w)
#endif

int main()
{
    int N, K, cnt = 0;
    int h, m, s, p, second;
    double total = 0;
    scanf("%d %d", &N, &K);
    customer_t customer[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        second = h * 3600 + m * 60 + s;
        customer[i].atime = second;
        customer[i].ptime = p * 60;
    }

    qsort(customer, N, sizeof(customer_t), cmp);

    showalltime();

    while (cnt < N && atime(cnt) <= 61200) {
        int mw = 0, mtime = windows[0];
        for (int j = 1; j < K; ++j) {
            if (windows[j] < mtime) {
                mtime = windows[j];
                mw = j;
            }
        }
        if (atime(cnt) < windows[mw]) {
            total += windows[mw] - atime(cnt);
            windows[mw] += ptime(cnt);
            showtime(cnt, mw);
        }
        else {
            windows[mw] = atime(cnt) + ptime(cnt);
            showtime(cnt, mw);
        }
        ++cnt;
    }
    printf("%.1lf\n", cnt == 0 ? 0.0 : total / 60.0 / cnt);

    return 0;
}
