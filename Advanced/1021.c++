#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, maxheight = 0;
bool visit[10010];
set<int> s;
vector<int> temp;
vector<vector<int>> map;

void dfs(int node, int height)
{
    if (height >= maxheight) {
        if (height > maxheight) {
            temp.clear();
            maxheight = height;
        }
        temp.push_back(node);
    }

    visit[node] = true;
    for (int i = 0; i < map[node].size(); ++i) {
        if (!visit[map[node][i]])
            dfs(map[node][i], height + 1);
    }
}


int main()
{
    scanf("%d", &n);
    map.resize(n + 1);
    int a, b, cnt;

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(1, 0); ++cnt;
    for (int j = 0; j < temp.size(); ++j)
        s.insert(temp[j]);
    for (int i = 2; i <= n; ++i) {
        if (!visit[i]) {
            dfs(i, 0); ++cnt;
        }
    }
    if (cnt > 1)
        printf("Error: %d components", cnt);
    else {
        maxheight = -1;
        fill(visit, visit + 10010, false);
        dfs(temp[0], 0);

        for (int i = 0; i < temp.size(); ++i)
            s.insert(temp[i]);
        for (auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
