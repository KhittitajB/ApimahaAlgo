nk = input()
n, k = nk.split()
n = int(n)
k = int(k)

vulaes = []

for i in range(n):
    xy = input()
    x, y = xy.split()
    x = int(x)
    y = int(y)
    vulaes.append(x-y)

# print(vulaes)
vulaes.sort(reverse=True)
# print(vulaes)

for j in vulaes:
    if j <= 0 and k > 0:
        vulaes.pop()
        k -= 1

print(sum(vulaes))