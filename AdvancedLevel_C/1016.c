#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ONE_BEGIN (0)
#define ONE_TOTAL (-1)
#define name(i) record[i].name
#define time(i) record[i].time
#define online(i) record[i].online
#define offline(i) !online(i)
#define sameone(i, j) (strcmp(name(i), name(j)) == 0)

#define D(i) time(i)[1]
#define H(i) time(i)[2]
#define M(i) time(i)[3]

#define month(i) time(i)[0]
#define day(i) D(i)
#define hour(i) (day(i) * 24 + H(i))
#define minute(i) (hour(i) * 60 + M(i))
#define status(i) (record[i].online? "on-line": "off-line")

#define input(t) scanf("%d:%d:%d:%d", &t[0], &t[1], &t[2], &t[3])
#define printDHM(i) printf("%02d:%02d:%02d", D(i), H(i), M(i))
#define printMDHM(i) printf("%02d:%02d:%02d:%02d", month(i), D(i), H(i), M(i))


typedef struct _record {
    char name[23];
    char time[4];
    bool online;
    int minute;
} record_t;

char status[16];
int N, rate[25];
int paired[1000], count;
record_t record[1000];

int cmp(const void *a, const void *b)
{
    record_t *aa = (record_t *)a;
    record_t *bb = (record_t *)b;
    int res = strcmp(aa->name, bb->name);
    return res != 0 ? res : aa->minute - bb->minute;
}

double bill(int i)
{
    double cost = D(i) * rate[24];
    for (int h = 0; h < H(i); ++h)
        cost += rate[h];
    cost += rate[H(i)] * M(i) / 60.0;
    cost /= 100.0;

    return cost;
}

int main()
{
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &rate[i]);
        rate[i] *= 60;
        rate[24] += rate[i];
    }
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%s", record[i].name);
        input(record[i].time);
        scanf("%s", status);
        record[i].online = (status[1] == 'n');
        record[i].minute = minute(i);
    }

    qsort(record, N, sizeof(record_t), cmp);

    paired[count++] = ONE_BEGIN;
    for (int i = 1; i < N; ++i) {
        if (offline(i)) {
            if (online(i - 1) && sameone(i - 1, i)) {
                if (count > 1 && !sameone(i, paired[count - 1])) {
                    paired[count++] = ONE_TOTAL;
                    paired[count++] = ONE_BEGIN;
                }
                paired[count++] = i;
            }
            ++i;
        }
    }
    paired[count++] = ONE_TOTAL;

    int minute, i;
    double total = 0, once;

    for (int j = 0; j < count; ++j) {
        switch (paired[j]) {
            case ONE_BEGIN:
                i = paired[j + 1];
                printf("%s %02d\n", name(i), month(i));
                total = 0;
                break;
            case ONE_TOTAL:
                printf("Total amount: $%.2lf\n", total);
                break;
            default:
                i = paired[j];
                minute = minute(i) - minute(i - 1);
                once = bill(i) - bill(i - 1);
                total += once;
                printDHM(i - 1); putchar(32);
                printDHM(i); putchar(32);
                printf("%d $%.2lf\n", minute, once);
        }
    }
}
