import sys, threading

def main1():
        total, pairs = map(int, input('').split())
        array_gold = list(map(int, input('').split()))
        unions = {}
        visiteds = set()
        array_gold = {i: array_gold[i] for i in range(len(array_gold))}



        def insert(x, y):
                x = x-1
                y = y-1
                if (x == y):
                        return
                if x not in unions:
                        unions[x] = set()
                if y not in unions:
                        unions[y] = set()
                unions[x].add(y)
                unions[y].add(x)


        for i in range(pairs):
                x, y = map(int, input('').split())
                insert(x, y)


        def dfs(start, min):
                visiteds.add(start)
                if (start in array_gold):
                        if (min > array_gold[start]):
                                min = array_gold[start]
                        del array_gold[start]
                for i in unions[start]:
                        if i not in visiteds:
                                tempMin = dfs(i, min)
                                if (tempMin < min):
                                        min = tempMin
                return min


        mins = 0
        for x in range(total):
                if x in unions and x not in visiteds:
                        min = array_gold[x]
                        min = dfs(x, min)
                        mins += min

        for i in array_gold:
                mins += array_gold[i]
        print(mins)

# Recursion and thread optimization if recursion limit reach
if __name__ == "__main__":
    sys.setrecursionlimit(9100000)
    threading.stack_size(134217728)
    main_thread = threading.Thread(target=main1)
    main_thread.start()
    main_thread.join()