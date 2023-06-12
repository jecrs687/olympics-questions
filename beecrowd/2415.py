unnecessary = input('')
values = list(map(int, input('').split()))

curr = values[0]
number_curr = 1
number_max = 1

for x in range(1,len(values)):
        value = values[x]
        if(value == curr):
                number_curr += 1
                if(number_curr > number_max):
                        number_max = number_curr
        else:
                curr = value
                number_curr = 1 
        

print(number_max)



