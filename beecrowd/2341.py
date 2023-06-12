
quantity = int(input(''))

values = [] 
max_total = 0
curr = 0
max_possible = pow(2000, 5000)
current_values = (0,0)
for x in range(quantity):
        if(max_total != max_possible):
                value = input('').split()
                i, j = int(value[0]), int(value[1])
                if(i > current_values[0] or j > current_values[1]):
                        total = pow(i, j)
                        if(total > max_total):
                                max_total = total
                                curr = x
                                current_values = (i,j)
                        else:
                                continue
                else:
                        continue
        else: 
                input('')

print(curr)



