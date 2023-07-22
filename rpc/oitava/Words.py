e=input()
vowel=['a','e','i','o','u']

v=False
c=False
r=1

for i in e:
    if(not(v) and not(c)):
        if(vowel.count(i)==1):
            v=True
        else:
            c=True
    elif(vowel.count(i)==1):
        if(c):
            v=True
            c=False
        else:
            r=0
            break
    else:
        if(v):
            c=True
            v=False
        else:
            r=0
            break

print(r)
