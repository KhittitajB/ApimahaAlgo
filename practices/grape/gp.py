import bisect

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break

    grid = [list(map(int, input().split())) for _ in range(n)]
    q = int(input())

    for _ in range(q):
        L, U = map(int, input().split())
        best = 0

        for i in range(n):
            pos = bisect.bisect_left(grid[i], L)
            size = best
            while i + size < n and pos + size < m and grid[i + size][pos + size] <= U:
                size += 1
            best = max(best, size)

        print(best)
    print("-")
