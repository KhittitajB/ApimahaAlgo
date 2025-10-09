from collections import deque

def bfs(start, graph, n):
    visited = [False] * (n + 1)
    q = deque([start])
    visited[start] = True
    order = []
    while q:
        node = q.popleft()
        order.append(node)
        for nei in graph[node]:
            if not visited[nei]:
                visited[nei] = True
                q.append(nei)
    return order

def dfs(start, graph, visited=None, order=None):
    if visited is None:
        visited = [False] * len(graph)
    if order is None:
        order = []
    visited[start] = True
    order.append(start)
    for nei in graph[start]:
        if not visited[nei]:
            dfs(nei, graph, visited, order)
    return order
