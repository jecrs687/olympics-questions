values = int(input(''))
friends = list(map(int,input('').split()))
errors = list(map(int,input('').split()))
friends.sort()
errors.sort()
memoization = {}

def verify(missings, errors, total):
        if(len(missings) == 0):
                return True
        first = missings[0]
        layer_copy = missings.copy()
        errors_copy = errors.copy()
        for i in range(len(errors)):
                error = errors[i]
                if((first+error == total or first-error==total)):
                        del errors_copy[i]
                        return verify(layer_copy[1:], errors_copy, total)
        return False
                
        

size = len(friends)
final = size-1


max_error= errors[final]
min_error = errors[0]

list_of_values = []

min_max  = verify(friends[1:],errors[0:size],friends[0] + max_error)
min_min  = verify(friends[1:],errors[0:size],friends[0] - max_error)
min_min1 = verify(friends[1:],errors[1:],friends[0] + min_error)
min_max1 = verify(friends[1:],errors[1:],friends[0] - min_error)

max_max  = verify(friends[:size],errors[0:size],friends[size-1] + max_error)
max_min  = verify(friends[:size],errors[0:size],friends[size-1] - max_error)
max_min1 = verify(friends[:size],errors[1:],friends[size-1] + min_error )
max_max1 = verify(friends[:size],errors[1:],friends[size-1] - min_error )

if(min_max):
        list_of_values.append(friends[0] + max_error)
if(min_min):
        list_of_values.append(friends[0] - max_error)
if(min_min1):
        list_of_values.append(friends[0] + min_error)
if(min_max1):
        list_of_values.append(friends[0] - min_error)
if(max_max):
        list_of_values.append(friends[size-1] + max_error)
if(max_min):
        list_of_values.append(friends[size-1] - max_error)
if(max_min1):
        list_of_values.append(friends[size-1] + min_error)
if(max_max1):
        list_of_values.append(friends[size-1] - min_error)


for i in list(set(list_of_values)): 
        print(i)
