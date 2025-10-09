from collections import deque, defaultdict

def solve():
    N, M, S, T = map(int, input().split())

    routes = []
    stop_to_routes = defaultdict(list)

    for i in range(M):
        data = list(map(int, input().split()))
        L = data[0]
        stops = data[1:]
        routes.append(stops)
        for stop in stops:
            stop_to_routes[stop].append(i)

    # BFS: nodes are bus stops (1..N) and routes (N..N+M-1)
    q = deque()
    visited_stop = [False] * (N + 1)
    visited_route = [False] * M
    dist = [float('inf')] * (N + 1)

    q.append((S, 0))
    visited_stop[S] = True
    dist[S] = 0

    while q:
        stop, d = q.popleft()
        if stop == T:
            print(d // 2)
            return

        # Try all routes passing through this stop
        for route in stop_to_routes[stop]:
            if visited_route[route]:
                continue
            visited_route[route] = True
            # Visit all stops in this route
            for next_stop in routes[route]:
                if not visited_stop[next_stop]:
                    visited_stop[next_stop] = True
                    q.append((next_stop, d + 1))

    print(-1)
