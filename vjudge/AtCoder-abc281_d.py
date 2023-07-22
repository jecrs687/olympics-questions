import sys, threading
max = -1

def main1():

        size, pairs, divisor = map(int, input('').split())
        array = list(map(int, input('').split()))[:size]
        visiteds = set()
        alreadyTried = set()
        memoize = {}
        size = len(array)
        def recursive(start, total, rest, local, init):
                global max
                local = local.copy()
                local.add(start)
                if (rest == 0):
                        if (total % divisor == 0 and total > max):
                                max = total
                else:
                        for x in range(init, len(array)):
                                value = array[x]
                                if x not in visiteds and x not in local and value not in alreadyTried:
                                        recursive(x, total+x, rest-1, local, init+1)
                

        for x in range(size):
                visiteds.add(x)
                localVisiteds = set()
                recursive(x, array[x], pairs-1, localVisiteds, x+1)
                alreadyTried.add(array[x])

        print(max)
# Recursion and thread optimization if recursion limit reach
if __name__ == "__main__":
    sys.setrecursionlimit(9100000)
    threading.stack_size(134217728)
    main_thread = threading.Thread(target=main1)
    main_thread.start()
    main_thread.join()