input('')
values = list(map(int, input('').split()))

value1 = 0
value2 = len(values)-1
total1 = 0
total2 = 0 
while(value1 != value2+1):
        if(total1 <= total2):
                total1 += values[value1]
                value1 += 1
        else:
                total2 += values[value2]
                value2 -= 1
print(value1)