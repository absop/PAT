/* 参考: https://blog.csdn.net/coord_/article/details/54974412# */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef struct _vertex {
    int vertex, dist;
} edge_t;

typedef struct _path {
    int need = 0;
    int back = 0;
    vector<int> vertexs;
} path_t;

int bike[501];
bool visit[501];
vector<vector<edge_t>> graph;
vector<vector<path_t>> paths;

void DIJKSTRA(int N)
{
    int u, v, d, mindst, dist[N + 1];
    path_t path;

    fill(dist, dist + N + 1, INT_MAX);
    dist[0] = 0;
    path.vertexs.push_back(0);
    paths[0].push_back(path);

    for (int i = 0; i < N; i++) {
        for (mindst = INT_MAX, v = 0; v <= N; v++) {
            if (!visit[v] && dist[v] < mindst) {
                mindst = dist[v];
                u = v;
            }
        }
        visit[u] = true;
        for (auto edge : graph[u]) {
            v = edge.vertex, d = edge.dist;
            if (visit[v]) continue;
            if (dist[u] + d > dist[v]) continue;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                paths[v].clear();
            }
            for (int j = 0; j < paths[u].size(); ++j) {
                path = paths[u][j];
                path.back += bike[v];
                if (path.back < 0) {
                    path.need -= path.back;
                    path.back = 0;
                }
                path.vertexs.push_back(v);
                paths[v].push_back(path);
            }
        }
    }
}

path_t select_optimal_path(int sp)
{
    path_t optimal;
    int need = INT_MAX, back = INT_MAX;
    for (auto path : paths[sp]) {
        if (path.need < need) {
            optimal = path;
            need = path.need;
            back = path.back;
        }
        else if (path.need == need && path.back < back) {
            optimal = path;
            back = path.back;
        }
    }
    return optimal;
}

int main()
{
    int Cmax, N, Sp, M;
    int r1, r2, weight;

    cin >> Cmax >> N >> Sp >> M;
    graph.resize(N + 1);
    paths.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> bike[i];
        bike[i] -= Cmax / 2;
    }
    for (int i = 0; i < M; i++) {
        cin >> r1 >> r2 >> weight;
        graph[r1].push_back({r2, weight});
        graph[r2].push_back({r1, weight});
    }

    DIJKSTRA(N);
    path_t path = select_optimal_path(Sp);
    cout << path.need << " " << path.vertexs[0];
    for (int i = 1; i < path.vertexs.size(); i++)
        cout << "->" << path.vertexs[i];
    cout << " " << path.back;

    return 0;
}
