#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct person {
    int arrive, start, time;
    bool vip;
} tempperson;

struct tablenode {
    int end = 8 * 3600, num;
    bool vip;
};

bool cmp1(person a, person b) { return a.arrive < b.arrive; }

bool cmp2(person a, person b) { return a.start < b.start; }

vector<person> player;
vector<tablenode> table;

int main()
{
    int n, k, m, viptable;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, m, s, temptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &temptime, &flag);
        tempperson.arrive = h * 3600 + m * 60 + s;
        tempperson.start = 21 * 3600;
        if (tempperson.arrive >= 21 * 3600) continue;
        tempperson.time = temptime <= 120 ? temptime * 60 : 7200;
        tempperson.vip = ((flag == 1) ? true : false);
        player.push_back(tempperson);
    }
    n = player.size();

    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    sort(player.begin(), player.end(), cmp1);
    int i = 0, vipid = -1;
    while (++vipid < n && !player[vipid].vip);
    while (i < n) {
        int index = -1, minendtime = INT_MAX;
        for (int j = 1; j <= k; j++) {
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
                vipid < n && player[vipid].arrive <= table[index].end)
                pid = vipid;
        }
        else if (player[i].vip) {
            int vipindex = -1, minvipendtime = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (table[j].vip && table[j].end < minvipendtime) {
                    minvipendtime = table[j].end;
                    vipindex = j;
                }
            }
            if (vipindex != -1 && player[i].arrive >= table[vipindex].end)
                tid = vipindex;
        }

        if (pid == i) i++;
        if (pid == vipid) while (++vipid < n && !player[vipid].vip);
        player[pid].start = max(player[pid].arrive, table[tid].end);
        table[tid].end = player[pid].start + player[pid].time;
        table[tid].num++;
    }
#define printtime(t) \
    printf("%02d:%02d:%02d ", (t) / 3600, ((t) / 60) % 60, (t) % 60)

    sort(player.begin(), player.end(), cmp2);
    for (i = 0; i < n && player[i].start < 21 * 3600; i++) {
        printtime(player[i].arrive);
        printtime(player[i].start);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for (int i = 1; i <= k; i++) {
        if (i != 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}
