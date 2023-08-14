


a = input()
a = a.split('-')
a.reverse()
a = [a for a in a if a != '']
value = list(a[0])
while(value[0] == '|'):
    value.remove('|')
value.reverse()
while(value[0] == '|'):
    value.remove('|')
print(value)