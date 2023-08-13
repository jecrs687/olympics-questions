import math
from collections import Counter

c=[]
n=int(input())
e=[]

for i in range(n):
    c.append(input())

count=Counter(c)
qtd=sum(count.values())
v=count.most_common()
sum=0

while(len(count)>1 and ((v[0][1]*100)/qtd)<51):

    x=min(count.items(), key=lambda x:x[1])
    if(((x[1]+sum)*100)/qtd>=51):
        break

    rev=list(reversed(count.items()))

    for i in rev:
        if(i[1]==x[1]):
            sum+=i[1]
            e.append(i[0])
            count.popitem()
        else:
            break

print(len(e))
for i in e:
    print(i)



