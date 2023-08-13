def is_primo(value):
        if value <= 1:
                return False
        for i in range(2, value):
                if value % i == 0:
                        return False
        return True

def repeat_one(my_dict):
        values = list(my_dict.values())
        for i in range(len(values)):
                for x in range(i+1, len(values)):
                        for w in range(len(values[i][0])):
                                if(values[i][0][w] in values[x][0]):
                                        return True
                

def possibles(a, arr):
        values = [];
        for i in arr:
                primo = is_primo(a+i)
                if(primo):
                        values.append(i)
        return [values, len(values)]
        
def remove_most_common_element(mydict):
        key = list(mydict.keys())[0];
        values = mydict[key][0];
        for i in values:
                if i != key:
                        mydict[i][0].remove(key)
                        mydict[i][1]-=1;
        del mydict[key]
        return mydict
                
        
         
                
        
n = int(input(''))
periodicities = list(map(int, input('').split()))
possibilities = {}
max = 0;
for i in periodicities:
        if(i in possibilities):
                possibilities[i][2]+=1        
        else:
                possibilities[i] =  possibles(i, periodicities)
                possibilities[i].append(1)
        
possibilities = dict(sorted(possibilities.items(), key=lambda item: item[1][1], reverse=True))
rep = repeat_one(possibilities)
if(rep):
        while (rep):
                possibilities = dict(sorted(possibilities.items(), key=lambda item: item[1][1], reverse=True))
                possibilities = remove_most_common_element(possibilities)
                rep = repeat_one(possibilities)
# sum of a arrays inside possibilities
print(sum(map(lambda x: x[1][2], possibilities.items())))

