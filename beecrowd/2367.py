def determine_winner(X, M):
    if M > X:
        X, M = M, X  # Inverte os valores de X e M se M for maior que X
    if X % (M + 1) == 0 or X % (M + 1) == 1:
        return 'Paula'  # Jogador B vence se X for múltiplo de (M + 1) ou X for um a mais que um múltiplo de (M + 1)
    else:
        return 'Carlos'  # Jogador A vence caso contrário

[arvores, cipo_distance] = list(map(int, input('').split()))

print(determine_winner(arvores, cipo_distance))


# Exemplo de uso
X = 5
M = 3
vencedor = determine_winner(X, M)
print(f"O jogador vencedor é: {vencedor}")

X = 20
M = 5
vencedor = determine_winner(X, M)
print(f"O jogador vencedor é: {vencedor}")

X = 3
M = 5
vencedor = determine_winner(X, M)
print(f"O jogador vencedor é: {vencedor}")