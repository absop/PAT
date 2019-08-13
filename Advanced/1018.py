def dijkstra(s):
    dist[s] = 0
    paths[s] = [[0, (0, 0)]]

    while graph:
        u, mdst = -1, inf
        for v in graph:
            if dist[v] < mdst:
                mdst = dist[v]
                u = v
        # The visited array no longer needed.
        for v, w in graph.pop(u):
            if dist[u] + w > dist[v]: continue
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                paths[v] = []
            for up in paths[u]:
                need, back = up[-1]
                back += bike[v]
                if back < 0:
                    need -= back
                    back = 0
                vp = up[:-1] + [v, (need, back)]
                paths[v].append(vp)

def select_optimal_path(sp):
    opt = [0, (0, 0)]
    need, back = inf, inf
    for path in paths[sp]:
        _need, _back = path[-1]
        if _need < need:
            need = _need
            back = _back
            opt = path
        elif _need == need and _back < back:
            opt = path
            back = _back
    return opt


inf = float("inf")
scanf = lambda: input().split(" ")
C, N, Sp, M = [int(i) for i in scanf()]
bike = [0] + [int(i) - C // 2 for i in scanf()]

graph = {v:[] for v in range(N + 1)}
paths = [[] for i in range(N + 1)]
dist = [inf for i in range(N + 1)]

for i in range(M):
    u, v, weight = [int(x) for x in scanf()]
    graph[u].append((v, weight))
    graph[v].append((u, weight))

dijkstra(0)
opt = select_optimal_path(Sp)
need, back = opt.pop()
print(need, end=' ')
print(*opt, end=' ', sep="->")
print(back)
