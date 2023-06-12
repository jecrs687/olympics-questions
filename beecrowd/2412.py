# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
import sys
[arvores, cipo_distance] = list(map(int, input('').split()))
distances = []

for x in range(arvores):
    distances.append(list(map(int, input('').split())))
    
sys.setrecursionlimit(arvores*5)
def sub(first, second):
    return [abs(first[0]-second[0]), abs(first[1]-second[1])]

def dfs(graph, vert, visited):
    visited.add(vert)
    for neighborhood in graph[vert]:
        if neighborhood not in visited:
            dfs(graph, neighborhood, visited)
            
def verify(distances, cipo_distance):
    founds = {}
    cipo_distance_2 = cipo_distance**2
    for x in range(len(distances)-1):
        first = distances[x];
        found = False
        for y in range(x+1, len(distances)):
            second = distances[y];
            [dis_x, dis_y] = sub(first, second)
            if(dis_x > cipo_distance or dis_y > cipo_distance):
                continue
            if(dis_x== cipo_distance and dis_y>0):
                continue
            if(dis_y==cipo_distance and dis_x>0):
                continue
            distanceAbs = (dis_x**2) + (dis_y**2)
            # print(first, second, [x,y], [x*x, y*y], distanceAbs)
            if( distanceAbs <= cipo_distance_2):
                found = True
                if(x in founds):
                    founds[x].append(y)
                else:
                    founds[x] = [y]
                if(y in founds):
                    founds[y].append(x)
                else:
                    founds[y] = [x]
        if(not found and x not in founds):
            return 'N'
    visited = set()
    keys = list(founds.keys())
    key = keys[0]
    dfs(founds, key, visited)
    if(len(keys) == len(visited)):
        return 'S'
    return 'N'
    
print(verify(distances,cipo_distance))


