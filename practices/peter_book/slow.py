while True:
    check = False

    stock = ""
    sub = 1000001

    n = input()

    if n == "":
        break
    else:
        n = int(n)

    seq = input()
    seq = list(map(int, seq.split()))

    goal = int(input())

    for i in range(len(seq)):
        if check:
            break
        for j in range(len(seq)):
            if check:
                break
            if i != j:
                res = seq[i]+seq[j]
                if res == goal:
                    ts = abs(seq[i] - seq[j])
                    if sub > ts:
                        if seq[i] > seq[j]:
                            stock = f"Peter should buy books whose prices are {seq[j]} and {seq[i]}."
                        else:
                            stock = f"Peter should buy books whose prices are {seq[i]} and {seq[j]}."
                        sub = ts

    print(stock)

    print("")