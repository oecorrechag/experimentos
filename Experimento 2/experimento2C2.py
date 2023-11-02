import numpy as np
import time
import random

# Definir la dimensión de la matriz N
N = 100

# Crear una matriz N x N con valores del 1 al 100
matriz = np.random.randint(1, 101, size=(N, N))
# Inicializar una matriz de resultados con ceros
resultado = np.zeros((N, N))

# Medir el tiempo antes de la multiplicación
inicio = time.time()

# Realizar la multiplicación de filas por columnas
for i in range(N):
    for j in range(N):
        resultado[i][j] = sum(matriz1[i] * matriz2[j])

# Medir el tiempo después de la multiplicación
fin = time.time()

# Calcular el tiempo transcurrido
tiempo_transcurrido = fin - inicio

# print("Matriz original:")
# print(matriz)
# print("\nResultado de la multiplicación:")
# print(resultado)
print(f"\nTiempo transcurrido: {tiempo_transcurrido} segundos")
