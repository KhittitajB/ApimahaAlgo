zuma = []
zn = []
nn = []

nm = input()
n, m = nm.split()
n = int(n)
m = int(m)

for i in range(n):
    ball = int(input())
    zuma.append(ball)

for x in range(len(zuma)):
    zn.append(x+1)

ll = len(zn)

for j in range(m):
    cl = input()
    c, l = cl.split()
    nn.append(ll+j+1)
    zn.insert((zn.index(int(l)))+1, nn[j])

for i in zn:
    print(i)