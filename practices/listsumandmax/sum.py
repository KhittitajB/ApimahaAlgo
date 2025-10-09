def is_empty(lst):
    return len(lst) == 0

def is_last(lst, index):
    return index == len(lst) - 1

def recursive_sum(lst, index=0):
    if is_empty(lst):
        return 0
    if is_last(lst, index):
        return lst[index]
    return lst[index] + recursive_sum(lst, index + 1)

# ---- main ----
n = int(input())
numbers = [int(input()) for _ in range(n)]

print(recursive_sum(numbers))
