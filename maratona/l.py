import math
lines, columns = map(int, input('').split())
quantity_sensors = int(input(''))
sensors = []
total = 0;
for x in range(quantity_sensors):
        x, y, range = map(int, input('').split())
        if(x>lines or y>columns):
                continue
        init_x, init_y, final_x, final_y = (x-range)-1, (y-range)-1, x+range, y+range
        if(init_x < 0):
                init_x = 0;
        if(init_y < 0):
                init_y = 0;
        if(final_x > lines):
                final_x = lines;
        if(final_y > columns):
                final_y = columns;     
        range_x = final_x - init_x
        range_y = final_y - init_y   
        total += (range_x * range_y)
        

response = math.floor(total/(lines*columns))
print(response)            
        


