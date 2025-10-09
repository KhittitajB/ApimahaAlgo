def count_components(graph, n):
    visited = [False] * (n + 1)
    def dfs(node):
        visited[node] = True
        for nei in graph[node]:
            if not visited[nei]:
                dfs(nei)

    count = 0
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i)
            count += 1
    return count
