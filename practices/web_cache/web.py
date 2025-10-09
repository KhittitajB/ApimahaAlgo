nm = input()
n, m = nm.split()
n = int(n)
m = int(m)

mxl = []
miss = 0

for i in range(m):
    cac = int(input())

    if cac in mxl:
        pass
    else:
        if len(mxl) < n:
            mxl.append(cac)
            miss += 1
        else:
            mxl.pop(0)
            mxl.append(cac)
            miss += 1

print(miss)