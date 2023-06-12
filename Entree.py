def fibonacciSoup(n):
        if(n == 0):
                return [1, 0]
        elif(n == 1):
                return [0, 1]
        elif(n == 2):
                return [0.5,0.5]
        a =  [0, 1]
        b = [0.5,0.5]
        
        for i in range(3, n+1):
                totalSum = [a[0] + b[0], a[1] + b[1]]
                total = sum(totalSum)
                a,b =b, [totalSum[0]/total, totalSum[1]/total]
        return b

n = int(input(''))
if( n < 42):
        [pi_percent, tau_percent] = fibonacciSoup(n-1)
        print(pi_percent*100, tau_percent*100)
else: 
        print(33.33333333, 66.66666666)

