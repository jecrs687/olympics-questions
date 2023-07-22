def guass(n):
    return int((n * (n + 1)) / 2)


total, max_value = list(map(int, input().split()))

value = guass(max_value)
rest = total % value
if max_value >= total:
    print("Paula")
else:
    if rest > max_value:
        if total  % 2 == 0:
            print("Carlos")
        print("Paula")
    else:
        print("Carlos")  