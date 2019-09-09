#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef struct _node {
    int node, dist, cost;
} edge_t;

int dist[500];
bool visit[500];
vector<vector<edge_t>> graph;
vector<vector<vector<int>>> paths;

void dijkstra(int start)
{
    int u, v, d, mdist;
    vector<int> path;

    fill(dist, dist + 500, INT_MAX);
    dist[start] = 0;
    path.push_back(0);
    path.push_back(start);
    paths[start].push_back(path);

    for (int i = 0; i < graph.size() - 1; ++i) {
        for (mdist = INT_MAX, v = 0; v < graph.size(); ++v) {
            if (!visit[v] && dist[v] < mdist) {
                mdist = dist[v];
                u = v;
            }
        }
        visit[u] = true;
        for (auto edge : graph[u]) {
            v = edge.node, d = edge.dist;
            if (visit[v]) continue;
            if (dist[u] + d > dist[v]) continue;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                paths[v].clear();
            }
            for (int j = 0; j < paths[u].size(); ++j) {
                paths[v].push_back(paths[u][j]);
                paths[v].end()[-1].push_back(v);
                paths[v].end()[-1][0] += edge.cost;
            }
        }
    }
}


int main()
{
    int N, M, S, D;
    int c1, c2, d, c;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    graph.resize(N); paths.resize(N);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        graph[c1].push_back({c2, d, c});
        graph[c2].push_back({c1, d, c});
    }

    dijkstra(S);

    vector<int> optimal_path = paths[D][0];
    for (int i = 1; i < paths[D].size(); ++i) {
        if (paths[D][i][0] < optimal_path[0])
            optimal_path = paths[D][i];
    }

    printf("%d", optimal_path[1]);
    for (int i = 2; i < optimal_path.size(); ++i)
        printf(" %d", optimal_path[i]);
    printf(" %d %d\n", dist[D], optimal_path[0]);

    return 0;
}
