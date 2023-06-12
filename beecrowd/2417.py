values = list(map(int, input('').split()))

[c_vic, c_emp, c_sal] = values[0:3]
[f_vic, f_emp, f_sal] = values[3:6]

c_points = (c_vic*3) + c_emp
f_points = (f_vic*3) + f_emp

if(c_points > f_points):
        print('C')
elif(f_points > c_points):
        print('F')
else:
        if(c_sal > f_sal):
                print('C')
        elif(f_sal > c_sal):
                print('F')
        else:
                print('=')
