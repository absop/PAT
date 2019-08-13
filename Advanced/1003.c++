#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAXX 0x3f3f3f3f
#define siz 505

using namespace std;

int mp[siz][siz], val[siz], path[siz], dis[siz];
int totval[siz], pathnum[siz];
int vis[siz];
int n, m, x, y;

void dijstra(int x)
{
    for (int i = 0; i < n; i++)
        dis[i] = MAXX;
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    dis[x] = 0;
    totval[x] = val[x];

    for (int i = 0; i < n; i++) {
        if (mp[x][i] != MAXX && i != x) {
            dis[i] = mp[x][i];
            totval[i] = totval[x] + val[i];
            path[i] = x;
            pathnum[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int minn = MAXX, mival = 0, u = x;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < minn) {
                minn = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                if (dis[u] + mp[u][j] < dis[j]) {
                    pathnum[j] = pathnum[u];
                    dis[j] = dis[u] + mp[u][j];
                    totval[j] = totval[u] + val[j];
                    path[j] = u;
                }
                else if (dis[u] + mp[u][j] == dis[j]) {
                    pathnum[j] += pathnum[u];
                    if (totval[j] < totval[u] + val[j]) {
                        totval[j] = totval[u] + val[j];
                        path[j] = u;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);

    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mp[i][j] = MAXX;
    }

    int a, b, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        mp[a][b] = min(mp[a][b], t);
        mp[b][a] = mp[a][b];
    }

    dijstra(x);

    printf("%d %d\n", pathnum[y], totval[y]);

    // 输出路径
    // stack<int> stk;

    // while (!stk.empty()) stk.pop();

    // int k = y;
    // stk.push(k);
    // while (k != x) {
    //     k = path[k];
    //     stk.push(k);
    // }
    // k = stk.top();
    // cout << k;
    // stk.pop();

    // while (!stk.empty()) {
    //     k = stk.top();
    //     cout << " " << k;
    //     stk.pop();
    // }
    // cout << endl;


    return 0;
}
