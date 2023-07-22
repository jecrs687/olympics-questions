from collections import deque

def topological_sort(graph, indegree):
    n = len(graph)
    result = []
    queue = deque()

    # Inicializa a fila com as tarefas de prioridade 0
    for i in range(n):
        if indegree[i] == 0:
            queue.append(i)

    # Executa a ordenação topológica
    while queue:
        task = queue.popleft()
        result.append(task)

        # Atualiza as dependências das tarefas adjacentes
        for adj_task in graph[task]:
            indegree[adj_task] -= 1
            if indegree[adj_task] == 0:
                queue.append(adj_task)

    # Verifica se todas as tarefas foram executadas
    if len(result) == n:
        return result
    else:
        return None

def main():
    # Leitura da entrada
    N, M = map(int, input().split())

    # Criação do grafo e inicialização do grau de entrada
    graph = [[] for _ in range(N)]
    indegree = [0] * N

    # Leitura das dependências
    for _ in range(M):
        A, B = map(int, input().split())
        graph[A].append(B)
        indegree[B] += 1

    # Ordenação topológica
    order = topological_sort(graph, indegree)

    # Imprime o resultado
    if order is None:
        print("*")
    else:
        for task in order:
            print(task)

if __name__ == "__main__":
    main()