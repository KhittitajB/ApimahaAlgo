import heapq

def dijkstra(graph, start, n):
    dist = [float('inf')] * (n + 1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        d, node = heapq.heappop(pq)
        if d > dist[node]:
            continue
        for nei, w in graph[node]:
            if dist[nei] > d + w:
                dist[nei] = d + w
                heapq.heappush(pq, (dist[nei], nei))
    return dist
