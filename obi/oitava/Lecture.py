def find_least_cost(L, T, cost):
    # Inicializar a matriz dp
    dp = [float('inf')] * (L + 1)
    dp[0] = 0

    # Calcular o custo mínimo para ministrar as palestras
    for i in range(1, L + 1):
        for j in range(T):
            for k in range(3):
                if i - k >= 0:
                    dp[i] = min(dp[i], dp[i - k] + cost[j][k])

    return dp[L]

# Leitura dos valores de entrada
L, T = map(int, input().split())
cost = []
for _ in range(T):
    cost.append(list(map(int, input().split())))

# Chamada da função para encontrar o custo mínimo
result = find_least_cost(L, T, cost)

# Impressão do resultado
print(result)
