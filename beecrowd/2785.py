quantity = int(input(''))
values = []
for x in range(quantity):
        values.append(list(map(int, input('').split())))

min_value = float('inf')
last_layer = sum(values[-1])
memoization = {}
def verify(sub_layers, x, y, total, deep=0):
        global last_layer
        to_slice = y+1 
        layers = sub_layers.copy()
        if len(layers)==1:
                sumatory = total + last_layer
                return sumatory
        if len(layers)<1:
                return total
        size = len(layers[0])
        i = layers.pop(0)
        total_x, total_y = float('inf'), float('inf')
        if (deep not in memoization):
                memoization[deep] = {}
        if(x not in memoization[deep]):
                memoization[deep][x] = {}
        if(y in memoization[deep][x]):
                return memoization[deep][x][y] + total
        if(x>0):
                total_x = verify(layers, x-1, y, total + sum(i[x-1: y]), deep+1)
        if(to_slice<=size):
                total_y = verify(layers, x, to_slice, total + sum(i[x: to_slice]), deep+1)
        if(total_x < total_y):
                memoization[deep][x][y] = total_x - total
                return total_x
        else:
                memoization[deep][x][y] = total_y - total
                return total_y
        
for i in range(len(values[0])):
        curr_min = verify(values[1:], i,i+1,values[0][i])   
        if(curr_min < min_value):
                min_value = curr_min
        



print(min_value)

