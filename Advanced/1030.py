inf = float("inf")
N, M, S, D = [int(i) for i in input().split(" ")]

graph = {v:[] for v in range(N)}
paths = [[] for i in range(N)]
dist = [inf for i in range(N)]

for i in range(M):
    u, v, d, cost = [int(x) for x in input().split(" ")]
    graph[u].append((v, d, cost))
    graph[v].append((u, d, cost))

# Dijkstra algorithm
dist[S] = 0
paths[S] = [[S, 0]]

while graph:
    u, mdst = -1, inf
    for v in graph:
        if dist[v] < mdst:
            mdst = dist[v]
            u = v
    # The visited array no longer needed.
    for v, d, cost in graph.pop(u):
        if dist[u] + d > dist[v]: continue
        if dist[u] + d < dist[v]:
            dist[v] = dist[u] + d
            paths[v] = []
        for tou in paths[u]:
            tov = tou[:-1] + [v, tou[-1] + cost]
            paths[v].append(tov)

opt = min(paths[D], key=lambda item: item[-1])
opt.insert(-1, dist[D])
print(*opt, sep=" ")
