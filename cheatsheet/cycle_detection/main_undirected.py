def has_cycle_undirected(graph, n):
    visited = [False] * (n + 1)
    def dfs(u, parent):
        visited[u] = True
        for v in graph[u]:
            if not visited[v]:
                if dfs(v, u):
                    return True
            elif v != parent:
                return True
        return False
    for i in range(1, n + 1):
        if not visited[i]:
            if dfs(i, -1):
                return True
    return False
