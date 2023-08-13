value = input('')
value2= input('')

value2  = value2.rjust(len(value), '0')
value= value.rjust(len(value2), '0')

answer = []
for i in range(len(value2)):
    x= int(value2[i])
    y = int(value[i])
    if((x<=2 and y<=2) or (x>=7 and y>=7)):
        answer.append('0')
    else:
        answer.append('9')

response = ''.join(answer)
print(response)