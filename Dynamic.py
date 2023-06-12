n, q = map(int, input('').split())
a = list(map(int, input('').split()))
a.sort()
values=[]
for i in range(q):
        values.append(list(map(int, input('').split())))
for i in range(len(values)):
    e=values[i]    
    if(e[0]==1):
        if(e[1]>a[len(a)-1]):
            a.append(e[1])
        else:
            v='n'
            for j in a:
                if(e[1]==j):
                    print(j)
                    print(e[1])
                    v='s'
                    print(v)
                    break

            if(v=='n'):
                for j in range(len(a)):
                    if(e[1]<a[j]):
                        a[j]=e[1]
                        break

    elif(e[0]==2):
        x=0
        y=len(a)-1

        for j in range(y):
            if(e[1]<=a[j]):
                x=j
                break

        for j in range(y,0,-1):
            if(e[2]>=a[j]):
                y=j
                break

        z=a[x:y+1]
        print(len(z))