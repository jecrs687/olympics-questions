[x,y] = list(map(int, input('').split()))
mapper = []
number = 0
for i in range(x):
        mapper.append(list(input('')))
for i in range(x):
        for j in range(y):
                if(mapper[i][j] == '#'):
                        if(i == 0 or j==0 or i== x-1 or j == y-1):
                                number +=1
                        else:
                                if(mapper[i-1][j] == '.' or mapper[i+1][j] == '.' or mapper[i][j-1] == '.' or mapper[i][j+1] == '.'):
                                        number +=1
print(number)
        

