values = list(map(float, input('').split()))

values.sort()

print("%.1f" %  sum(values[1:4]))