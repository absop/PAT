#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define val(c) (c - 'A')
#define chr(v) (v + 'A')
#define hash(s) ((val(s[0]) * 26 + val(s[1])) * 26 + val(s[2]))

int idcnt = 1, anscnt;
int number[17576], string[2010];
int G[2010][2010], W[2010];
bool visit[2010];
struct _gang {
    int head;
    int num;
} ans[2010];

void tostring(int hash, char *name)
{
    name[2] = chr(hash % 26); hash /= 26;
    name[1] = chr(hash % 26); hash /= 26;
    name[0] = chr(hash % 26);
}

int tonumber(char *name)
{
    int hash = hash(name);
    if (number[hash] == 0) {
        number[hash] = idcnt;
        string[idcnt++] = hash;
    }
    return number[hash];
}

#define cvptr const void *
#define head(ptr) ((struct _gang*)ptr)->head
int cmp(cvptr a, cvptr b) { return head(a) < head(b) ? -1 : 1; }

void dfs(int u, int *head, int *numMember, int *totalweight)
{
    visit[u] = true;
    ++*numMember;
    if (W[u] > W[*head])
        *head = u;
    for (int v = 1; v < idcnt; v++) {
        if (G[u][v] > 0) {
            *totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if (!visit[v])
                dfs(v, head, numMember, totalweight);
        }
    }
}


int main()
{
    int N, K, time, id1, id2;
    char s1[4], s2[4];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%s %s %d", s1, s2, &time);
        id1 = tonumber(s1);
        id2 = tonumber(s2);
        W[id1] += time;
        W[id2] += time;
        G[id1][id2] += time;
        G[id2][id1] += time;
    }

    for (int u = 1; u < idcnt; ++u) {
        if (!visit[u]) {
            int head = u, numMember = 0, totalweight = 0;
            dfs(u, &head, &numMember, &totalweight);
            if (numMember > 2 && totalweight > K) {
                ans[anscnt++] = (struct _gang) {string[head], numMember};
            }
        }
    }
    printf("%d\n", anscnt);
    qsort(ans, anscnt, sizeof(ans[0]), cmp);
    for (int i = 0; i < anscnt; ++i) {
        tostring(ans[i].head, s1);
        printf("%s %d\n", s1, ans[i].num);
    }
}
