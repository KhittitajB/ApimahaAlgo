def dfs(node, graph, visited, crash):
    if node == crash:
        return
    visited[node] = True
    for nxt in graph[node]:
        if not visited[nxt] and nxt != crash:
            dfs(nxt, graph, visited, crash)

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

max_fail = 0

# Try crashing each node except 1
for crash in range(2, n + 1):
    visited = [False] * (n + 1)
    dfs(1, graph, visited, crash)

    fail_count = 0
    for i in range(1, n + 1):
        if not visited[i]:
            fail_count += 1

    if fail_count > max_fail:
        max_fail = fail_count

print(max_fail)
