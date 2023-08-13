def contar_orientacoes_reta(distancia):
    if distancia == 0:
        return 0

    orientacoes = 0

    # Caso vertical
    if distancia % 2 == 0:
        orientacoes += 1

    # Caso horizontal
    if distancia % 2 == 0:
        orientacoes += 1

    # Caso com inclinação
    for x1 in range(1, distancia):
        y1 = 0
        x2 = distancia - x1
        y2 = distancia

        if abs(y2 - y1) % abs(x2 - x1) == 0:
            orientacoes += 1

    # Caso com inclinação e tamanho ímpar
    for x1 in range(1, distancia // 2 + 1):
        y1 = 0
        x2 = distancia - x1
        y2 = distancia

        if abs(y2 - y1) % abs(x2 - x1) == 0 and (y2 - y1) * (x2 - x1) > 0:
            orientacoes += 1

    return orientacoes

# Exemplo de uso
tamanho_reta = 6
numero_orientacoes = contar_orientacoes_reta(tamanho_reta)
print(f"O número de orientações possíveis para uma reta de tamanho {tamanho_reta} é {numero_orientacoes}.")
