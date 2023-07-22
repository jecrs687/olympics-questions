x = int(input(''))
y = int(input(''))

if(x%2 == 0):
    if(y%2 == 0):
        print(1)
    else:
        print(0)
else:
    if(y%2 == 0):
        print(0)
    else:
        print(1)