def is_empty(lst):
    return len(lst) == 0

def is_last(lst, index):
    return index == len(lst) - 1

def recursive_max(lst, index=0):
    if is_empty(lst):
        return 0  # or some base case; list won't be empty per problem
    if is_last(lst, index):
        return lst[index]

    current = lst[index]
    next_max = recursive_max(lst, index + 1)

    if current > next_max:
        return current
    else:
        return next_max

# ---- main ----
n = int(input())
numbers = [int(input()) for _ in range(n)]

print(recursive_max(numbers))
