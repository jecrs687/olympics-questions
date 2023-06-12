import asyncio
import time
islands, fiber = list(map(int, input('').split()))
graph = {}
max_value = 0;
min_value = float('inf')
distances = {}       

for x in range(fiber):
        value = input('').split()
        initial, final,ping = int(value[0]), int(value[1]), int(value[2])
        if initial not in graph:
                graph[initial] = {}
        if final not in graph:
                graph[final] = {}
        if(final in graph[initial]):
                if(graph[initial][final] > ping):
                        graph[initial][final] = ping
                        graph[final][initial] = ping
                continue
        graph[initial][final] = ping
        graph[final][initial] = ping
        
initial_island = int(input(''))
distances[initial_island] = 0

async def verifyBranch(curr, graphCompleted, visited, total = 0,):
        global distances, initial_island, min_value
        visitedCurr =  visited.copy()
        all_promises = []
        if(set(graphCompleted[curr].keys()).issubset(set(visited))):
                return;
        for x in graphCompleted[curr]:
                if x == initial_island:
                        continue                       
                if x not in visited:
                        new_total = total + graphCompleted[curr][x]
                        if(len(distances) == len(graphCompleted) and x in distances and new_total > distances[x]   ):
                                continue
                        if x not in distances:
                                distances[x] = float('inf') 
                        visitedCurr.append(x)
                        # task = asyncio.create_task(
                        #         verifyBranch(x, graphCompleted, visitedCurr, new_total)
                        #         )
                        # await task
                        all_promises.append(verifyBranch(x, graphCompleted, visitedCurr, new_total))
                        if(new_total < distances[x]):
                                distances[x] = new_total
                                if (new_total < min_value):
                                        min_value = new_total
        await asyncio.gather(*all_promises)
        return

async def verify():
        initial = time.time_ns()
        # for x in range(20000):
        await verifyBranch(initial_island,  graph, [initial_island])
        # print(f"finished at {(time.time_ns()-initial)/10000000}")
        total_values = distances.values()
        print(max(total_values) - min_value)
async def main():
  await verify()

loop = asyncio.get_event_loop()
loop.run_until_complete(main())
loop.close()
                        
                        

