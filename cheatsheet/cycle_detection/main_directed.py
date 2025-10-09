def has_cycle_directed(graph, n):
    visited = [0] * (n + 1)
    def dfs(u):
        visited[u] = 1
        for v in graph[u]:
            if visited[v] == 1:
                return True
            if visited[v] == 0 and dfs(v):
                return True
        visited[u] = 2
        return False
    for i in range(1, n + 1):
        if visited[i] == 0:
            if dfs(i):
                return True
    return False
