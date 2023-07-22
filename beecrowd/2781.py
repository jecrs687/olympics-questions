checkTotal, habitants = list(map(int, input().split()))

graph = {}
graph2 = {}
paths={}
for i in range(checkTotal):
        sender, value, recipe = list(map(int, input().split()))
        discount = 0
        if(sender not in graph):
                graph[sender] = {}
                graph[sender][recipe] = value
        else:
                if(recipe not in graph[sender]):
                        graph[sender][recipe] = value
                else:
                        graph[sender][recipe] += value
                                
        if(sender in graph2):
                if(recipe in graph2[sender]):
                        if(
                                graph[sender][recipe]
                                > graph2[sender][recipe]
                        ):
                                discount = graph2[sender][recipe]
                                graph[sender][recipe] -= discount
                                del graph2[sender][recipe]
                                del graph[recipe][sender]
                        else:
                                discount = graph[sender][recipe]
                                graph2[sender][recipe] -= discount
                                del graph[sender][recipe]
                                continue
                                
        if(recipe not in graph2):
                graph2[recipe] = {}
                graph2[recipe][sender] = value
        else:
                if(sender not in graph2[recipe]):
                        graph2[recipe][sender] = value -  discount
                else:
                        graph2[recipe][sender] += value - discount



def find_paths2(current, initial):
        global graph, paths
        if current not in graph: 
                return
        for recipe in graph[current]:
                if(recipe not in paths[initial]):
                        paths[initial].append(recipe)
                        if(recipe not in paths):
                                find_paths2(recipe, initial)
                        else:
                                paths[initial] = paths[initial] + paths[recipe]
                        

def find_paths():
        global graph, paths
        for sender in graph:
                if(sender not in paths):
                        paths[sender] = []
                for recipe in graph[sender]:
                        paths[sender].append(recipe)
                        if(recipe not in paths):
                                find_paths2(recipe, sender)
                        else:
                                paths[sender] = paths[sender] + paths[recipe]
                paths[sender] = list(set(paths[sender]))

                                
                
                
def remove_cycles():
        global graph
        
find_paths()                                      
print('ok')
print('ok')