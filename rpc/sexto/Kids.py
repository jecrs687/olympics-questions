bridgt, child = map(int, input().split())
steps =  list(input())

dic = {
        'L': 'R',
        'R': 'L'
}
curr = 'L'    
def verify(steps,curr, child):
        for i in range(0, bridgt):
                step = steps[i]
                if(step != curr):
                        child-=1;
                        curr = dic[step]
                else:
                        curr = dic[curr]
                if(child == 0):
                        return 0
        return child
print(verify(steps,curr, child))
        