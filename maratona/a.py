def validate(value):
        moreThanOneO = value.count('O') != 1 or value.count('X') != 2
        if (moreThanOneO):
                return "?"
        if("XX" in value):
                return "Alice"
        else: 
                return "*"
value = input('')
print(validate(value))