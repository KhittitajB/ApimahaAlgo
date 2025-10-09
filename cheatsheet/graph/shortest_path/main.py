def shortest_path_unweighted(graph, start, n):
    dist = [-1] * (n + 1)
    dist[start] = 0
    from collections import deque
    q = deque([start])
    while q:
        node = q.popleft()
        for nei in graph[node]:
            if dist[nei] == -1:
                dist[nei] = dist[node] + 1
                q.append(nei)
    return dist
