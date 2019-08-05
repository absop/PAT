#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct _player {
    int arrive;
    int begin;
    int play;
    int vip;
} player[10001];

struct _table {
    int end;
    int vip;
    int num;
} table[101] = {[0 ... 100] = {.end = 8 * 3600}};

#define max(a, b) ((a) >= (b)? (a): (b))
#define atime(ptr) ((struct _player*)ptr)->arrive
#define btime(ptr) ((struct _player*)ptr)->begin
#define cvp const void *
int cmpa(cvp a, cvp b) { return atime(a) <= atime(b) ? -1 : 1; }
int cmpb(cvp a, cvp b) { return btime(a) <= btime(b) ? -1 : 1; }

int main()
{
    int N, K, H, M, S, m, vip, cnt = 0;
    scanf("%d", &N);
    for (int i = 0;  i < N; ++i) {
        scanf("%d:%d:%d %d %d", &H, &M, &S, &m, &vip);
        int arrive = H * 3600 + M * 60 + S;
        if (arrive >= 21 * 3600) continue;
        int play = m < 120 ? m * 60 : 7200;
        player[cnt++] = (struct _player) {arrive, 21 * 3600, play, vip};
    }
    N = cnt;

    scanf("%d %d", &K, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &vip);
        table[vip].vip = true;
    }
    qsort(player, N, sizeof(struct _player), cmpa);

    int i = 0, vipid = -1;
    while (++vipid < N && !player[vipid].vip);
    while (i < N) {
        int index = -1, minendtime = INT_MAX;
        for (int j = 1; j <= K; j++) {
            if (table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        if (table[index].end >= 21 * 3600) break;
        if (player[i].vip && i < vipid) {
            i++;
            continue;
        }
        int pid = i, tid = index;
        if (table[index].vip) {
            if (player[i].vip ||
                vipid < N && player[vipid].arrive <= table[index].end)
                pid = vipid;
        }
        else if (player[i].vip) {
            int vipindex = -1, minvipendtime = INT_MAX;
            for (int j = 1; j <= K; j++) {
                if (table[j].vip && table[j].end < minvipendtime) {
                    minvipendtime = table[j].end;
                    vipindex = j;
                }
            }
            if (vipindex != -1 && player[i].arrive >= table[vipindex].end)
                tid = vipindex;
        }

        if (pid == i) i++;
        if (pid == vipid) while (++vipid < N && !player[vipid].vip);
        player[pid].begin = max(player[pid].arrive, table[tid].end);
        table[tid].end = player[pid].begin + player[pid].play;
        table[tid].num++;
    }

#define printtime(t) \
    printf("%02d:%02d:%02d ", (t) / 3600, ((t) / 60) % 60, (t) % 60)

    qsort(player, N, sizeof(struct _player), cmpb);
    for (i = 0; i < N && player[i].begin < 21 * 3600; i++) {
        printtime(player[i].arrive);
        printtime(player[i].begin);
        printf("%.0f\n", round((player[i].begin - player[i].arrive) / 60.0));
    }
    for (int i = 1; i <= K; i++) {
        if (i != 1) printf(" ");
        printf("%d", table[i].num);
    }

    return 0;
}
