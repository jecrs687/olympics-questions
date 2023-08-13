def ordenar_cartas(string):
    ordem = string[0]
    for letter in string:
        if letter in ordem:
            continue
        else:
            ordem = ordem + letter

    string_ordenada = ""
    for letter in ordem:
        string_ordenada += (letter * string.count(letter))

    movimentos = 0
    for i, letter in enumerate(string_ordenada):
        if (letter == ordem[-1]):
            break
        elif (letter == string[i-movimentos]):
            continue
        else:
            movimentos += 1

    return movimentos
    
entrada = input('')
print(ordenar_cartas(entrada))