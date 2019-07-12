#include <stdio.h>
#include <stdlib.h>

typedef struct _customer {
    int atime;  // by second
    int ptime;  // by second
} __customer;
int windows[100] = {[0 ... 99] = 8 * 3600};

int cmp(const void *a, const void *b)
{
    return ((__customer *)a)->atime - ((__customer *)b)->atime;
}

char *strtime(int time)
{
    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = time % 60;
    char *buf = (char *)malloc(16);
    sprintf(buf, "%02d:%02d:%02d", h, m, s);
    return buf;
}

#define atime(i) customer[i].atime
#define ptime(i) customer[i].ptime
// #define min(a, b) (((a) <= (b))? (a): (b))
// #define ptime(i) min(3600, customer[i].ptime)
#if 0
    #define end(w) windows[w]
    #define format "%d service at window %d: %s - %s\n"
    #define outtime(i, w, b, e) printf(format, i, w, strtime(b), strtime(e))
    #define out(i) printf("%d %s %d\n", i, strtime(atime(i)), ptime(i) / 60)
    #define showalltime() for (int i = 0; i < N; ++i) out(i)
    #define showtime(i, w) outtime(i, w, end(w) - ptime(i), end(w))
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
    __customer customer[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        second = h * 3600 + m * 60 + s;
        customer[i].atime = second;
        customer[i].ptime = p * 60;
    }

    qsort(customer, N, sizeof(__customer), cmp);

    showalltime();

    while (cnt < N && customer[cnt].atime <= 61200) {
        int mw = 0, mtime = windows[0];
        for (int j = 1; j < K; ++j) {
            if (windows[j] < mtime) {
                mtime = windows[j];
                mw = j;
            }
        }
        if (customer[cnt].atime < windows[mw]) {
            total += windows[mw] - customer[cnt].atime;
            windows[mw] += ptime(cnt);
            showtime(cnt, mw);
        }
        else {
            windows[mw] = customer[cnt].atime + ptime(cnt);
            showtime(cnt, mw);
        }
        ++cnt;
    }
    if (cnt == 0)
        printf("0.0\n");
    else
        printf("%.1lf\n", total / 60.0 / cnt);

    return 0;
}
