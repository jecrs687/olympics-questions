number, instruction = list(map(int, input('').split()))

instructions = []
inverses = []

for x in range(0,instruction):
        instructions.append(input('').split())
        
def sum_list(initial, final):
        list_of_numbers = list(range(1,final+1))
        for i in inverses:
                if(i[1]<=final):
                        list_of_numbers[i[0]:i[1]] = list_of_numbers[i[0]:i[1]][::-1]
        value = sum(list_of_numbers[initial:final])
        print(value)

def reverse_list(initial, final):
        inverses.append([initial,final])
        return list

for instruction_cur in instructions:
        couple_of_numbers = list(map(int, instruction_cur[1:]))
        x = [instruction_cur[0]] + couple_of_numbers
        if(x[0] == 'S'):
                sum_list(x[1]-1,x[2])
        else:
                reverse_list(x[1]-1,x[2])
    