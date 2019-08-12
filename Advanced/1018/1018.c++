/*
 * https://blog.csdn.net/coord_/article/details/54974412#
 * 修改此页面代码而来。
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

const int Nmax = 501;
int Cmax, N, Sp, M, C2;
int bike[Nmax];
int map[Nmax][Nmax];
int take, rtn;

int dist[Nmax];
bool visit[Nmax];
vector<vector<int>> path[Nmax];

void DIJKSTRA()
{
    fill(visit, visit + Nmax, false);
    fill(dist, dist + Nmax, INT_MAX);
    dist[0] = 0;

    vector<int> v;
    v.push_back(0);
    path[0].push_back(v);

    for (int j = 0; j <= N; j++) {
        int min = INT_MAX;
        int k = -1;
        for (int i = 0; i <= N; i++) {
            if (!visit[i] && dist[i] < min) {
                min = dist[i];
                k = i;
            }
        }
        if (k == -1) break;
        visit[k] = true;
        for (int i = 0; i <= N; i++) {
            if (!visit[i] && map[k][i] != INT_MAX) {
                if (dist[k] + map[k][i] > dist[i]) continue;
                if (dist[k] + map[k][i] < dist[i]) {
                    dist[i] = dist[k] + map[k][i];
                    path[i].clear();
                }
                for (int l = 0; l < path[k].size(); l++) {
                    path[i].push_back(path[k].at(l));
                    path[i].at(path[i].size() - 1).push_back(i);
                }
            }
        }
    }
}

int select_optimal_path(int sp)
{
    int opt = -1;
    take = rtn = INT_MAX;
    for (int i = 0; i < path[sp].size(); i++) {
        vector<int> p = path[sp].at(i);
        int tk = 0, rt = 0;
        for (int j = 1; j < p.size(); j++) {
            if (bike[p.at(j)] == 0) continue;
            int remain = rt + bike[p.at(j)];
            if (bike[p.at(j)] > 0 || remain > 0)
                rt = remain;
            else {
                tk -= remain;
                rt = 0;
            }
        }
        if (tk < take) {
            opt = i;
            take = tk;
            rtn = rt;
        }
        else if (tk == take && rt < rtn) {
            opt = i;
            rtn = rt;
        }
    }
    return opt;
}

int main()
{
    cin >> Cmax >> N >> Sp >> M;
    for (int i = 1; i <= N; i++) {
        cin >> bike[i];
        bike[i] -= Cmax / 2;
    }
    int r1, r2, weight;
    fill(map[0], map[0] + Nmax * Nmax, INT_MAX);
    for (int i = 0; i < M; i++) {
        cin >> r1 >> r2 >> weight;
        map[r2][r1] = map[r1][r2] = weight;
    }

    DIJKSTRA();
    int o = select_optimal_path(Sp);
    vector<int> v = path[Sp].at(o);

    cout << take << " " << v.at(0);
    for (int i = 1; i < v.size(); i++)
        cout << "->" << v.at(i);
    cout << " " << rtn;

    return 0;
}
