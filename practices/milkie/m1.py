def can_fill(vessels, m, capacity):
    containers = 1
    current = 0
    for milk in vessels:
        if milk > capacity:
            return False
        if current + milk <= capacity:
            current += milk
        else:
            containers += 1
            current = milk
            if containers > m:
                return False
    return True

while True:
    try:
        nm = input().strip()
        if not nm:
            break
        n, m = map(int, nm.split())
        vessels = list(map(int, input().split()))

        left = max(vessels)
        right = sum(vessels)
        answer = right

        while left <= right:
            mid = (left + right) // 2
            if can_fill(vessels, m, mid):
                answer = mid
                right = mid - 1
            else:
                left = mid + 1

        print(answer)
    except EOFError:
        break
