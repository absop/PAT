#include <stdio.h>
#include <stdlib.h>

struct _station {
    double price, dist;
} stat[501];

#define FORMAT "The maximum travel distance = %.2f"
#define print_and_return(n) {printf(FORMAT, n); return 0;}
#define dist(ptr) ((struct _station *)ptr)->dist
#define cvptr const void *
int cmp1(cvptr a, cvptr b) { return dist(a) < dist(b) ? -1 : 1; }

int main()
{
    double Cm, D, Da;
    int N;
    scanf("%lf%lf%lf%d", &Cm, &D, &Da, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf%lf", &stat[i].price, &stat[i].dist);
        stat[i].price /= Da;
    }
    stat[N].dist = D;

    qsort(stat, N, sizeof(stat[0]), cmp1);

    if (stat[0].dist != 0) print_and_return(0);
    double total_price = 0, tank = 0;
    double Dm = Cm * Da, add, delta, min_price;

    for (int next, i = 0; stat[i].dist < D; i = next) {
        next = -1; min_price = 1e100;
        for (int j = i + 1; j <= N &&
            stat[j].dist <= stat[i].dist + Dm; j++) {
            if (stat[j].price <= stat[i].price) {
                next = j;
                break;
            }
            if (stat[j].price < min_price) {
                min_price = stat[j].price;
                next = j;
            }
        }
        if (next == -1) print_and_return(stat[i].dist + Dm);
        delta = stat[next].dist - stat[i].dist;
        if (min_price != stat[next].price) { // break from first if
            add = delta - tank;
            tank = 0;
        }
        else {
            add = Dm - tank;
            tank = Dm - delta;
        }
        total_price += stat[i].price * add;
        // printf("station:%d, add:%.0lf\n", i, add);
    }
    printf("%.2f", total_price);
    return 0;
}
