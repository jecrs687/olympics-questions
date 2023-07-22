momoize = {}


def is_prime(n):

    if n < 2:
        return False
    middle = int(n/2) + 1
    for i in range(2, middle):
        if n % i == 0:
            return False
    return True


def is_square(n):
    value = n**0.5
    return value == int(value)


def is_prime_or_square(attempt):
    if attempt in momoize:
        return momoize[attempt]
    if is_prime(attempt):
        return True
    if is_square(attempt):
        return True
    momoize[attempt] = False
    return False


input('')
number = list(map(int, list(input(''))))


def recursive(rest, total):
    if len(rest) == 0:
        return total
    restCopy = rest.copy()
    value = str(restCopy.pop(0))
    if (value == "0"):
        return recursive(restCopy, total)
    if (len(rest) == 0):
        return total
    if (is_prime_or_square(int(value))):
        return recursive(restCopy, total+1)
    else:
        while (not is_prime_or_square(int(value)) and len(restCopy) > 0):
            value += str(restCopy.pop(0))
        if (len(restCopy) == 0):
            rest.pop(0)
            return recursive(rest, total)
        else:
            return recursive(restCopy, total+1)


print(recursive(number, 0))