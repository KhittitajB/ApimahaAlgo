def is_bipartite(graph):
    color = {}

    for start in graph:
        if start not in color:
            color[start] = 0
            stack = [start]

            while stack:
                node = stack.pop()
                for nei in graph[node]:
                    if nei not in color:
                        color[nei] = 1 - color[node]
                        stack.append(nei)
                    elif color[nei] == color[node]:
                        return False
    return True


while True:
    es = []

    n = int(input())

    if n == 0:
        break

    l = int(input())
    for i in range(l):
        e1, e2 = map(int, input().split())
        es.append((e1, e2))

    graph = {i: [] for i in range(n)}
    for a, b in es:
        graph[a].append(b)
        graph[b].append(a)

    if is_bipartite(graph):
        print("BICOLORABLE.")
    else:
        print("NOT BICOLORABLE.")
