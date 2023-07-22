import math
value = int(input(''))
print(value)
while(not (value<10)):
        converted = math.floor(value/10) *3
        rest = value % 10
        value = converted + rest
        print(value)
