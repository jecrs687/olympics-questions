houses = int(input(''))

values = {}
for x in range(houses):
        value = int(input(''))
        if(value in values):
                values[value] += 1
        else:
                values[value] = 1
total = int(input(''))
number = []
for x in values.keys():
        temp = total - x;
        if(temp in values):
                if(temp == x):
                        if(values[temp] > 1):
                                number = [x,x]
                else:
                        number = [x,temp]
        else:
                continue
number.sort()

print(number[0],number[1])

