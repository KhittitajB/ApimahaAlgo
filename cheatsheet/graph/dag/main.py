def topo_sort(graph, n):
    indeg = [0] * (n + 1)
    for u in range(1, n + 1):
        for v in graph[u]:
            indeg[v] += 1

    from collections import deque
    q = deque([i for i in range(1, n + 1) if indeg[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in graph[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    return order
