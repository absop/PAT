#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define dist(u, v) map[u][v][0]
#define cost(u, v) map[u][v][1]

int dist[500];
int map[500][500][2];
bool visit[500];
vector<vector<int>> paths[500];

void dijkstra(int start, int N)
{
    fill(dist, dist + 500, INT_MAX);
    dist[start] = 0;

    vector<int> path;
    path.push_back(0);
    path.push_back(start);
    paths[start].push_back(path);

    for (int i = 0; i < N; ++i) {
        int mdist = INT_MAX, u = -1;
        for (int j = 0; j < N; ++j) {
            if (!visit[j] && dist[j] < mdist) {
                mdist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!visit[v] && dist(u, v) != 0x7fff) {
                if (dist[u] + dist(u, v) > dist[v]) continue;
                if (dist[u] + dist(u, v) < dist[v]) {
                    dist[v] = dist[u] + dist(u, v);
                    paths[v].clear();
                }
                for (int j = 0; j < paths[u].size(); ++j) {
                    paths[v].push_back(paths[u][j]);
                    paths[v][paths[v].size() - 1][0] += cost(u, v);
                    paths[v][paths[v].size() - 1].push_back(v);
                }
            }
        }
    }
}


int main()
{
    int N, M, S, D;
    int c1, c2, d, c;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    fill(map[0][0], map[0][0] + 500 * 500 * 2, 0x7fff);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        dist(c1, c2) = dist(c2, c1) = d;
        cost(c1, c2) = cost(c2, c1) = c;;
    }

    dijkstra(S, N);

    int optimal_cost = INT_MAX;
    vector<int> optimal_path;
    for (int i = 0; i < paths[D].size(); ++i) {
        if (paths[D][i][0] < optimal_cost) {
            optimal_cost = paths[D][i][0];
            optimal_path = paths[D][i];
        }
    }

    printf("%d", optimal_path[1]);
    for (int i = 2; i < optimal_path.size(); ++i)
        printf(" %d", optimal_path[i]);
    printf(" %d %d\n", dist[D], optimal_cost);

    return 0;
}
