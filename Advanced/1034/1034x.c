#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define val(c) (c - 'A')
#define hash(s) ((val(s[0]) * 26 + val(s[1])) * 26 + val(s[2]))

int idcnt = 1, anscnt;
int G[2010][2010], W[2010], number[17576];
char *string[2010], buffer[2010][4];;
bool visit[2010];
struct _gang {
    char *head;
    int num;
} ans[2010];

int tonumber(char *str)
{
    int hash = hash(str);
    if (number[hash] == 0) {
        number[hash] = idcnt;
        string[idcnt++] = str;
    }
    return number[hash];
}

#define cvptr const void *
#define head(ptr) ((struct _gang*)ptr)->head
int cmp(cvptr a, cvptr b) { return strcmp(head(a), head(b)); }

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
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        char *s1 = buffer[2 * i];
        char *s2 = buffer[2 * i + 1];
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
    for (int i = 0; i < anscnt; ++i)
        printf("%s %d\n", ans[i].head, ans[i].num);
}
