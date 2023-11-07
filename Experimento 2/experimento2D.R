# Especifica la dimensión de la matriz (N)
N <- 500

# Genera una matriz aleatoria de dimensiones NxN con valores entre 1 y 100
matriz <- matrix(sample(1:100, N*N, replace = TRUE), nrow = N, ncol = N)
# print(matriz)

matriz2 <- t(matriz)
# print(matriz2)

# Mide el tiempo de multiplicación de la matriz por sí misma
tiempo_inicio <- Sys.time()

## filas x columnas
resultado <- matrix(0, nrow = N, ncol = N)
for (i in 1:N) {
  for (j in 1:N) {
    for (k in 1:N) {
      resultado[i, j] <- resultado[i, j] + matriz[i, k] * matriz2[j, k]
    }
  }
}

tiempo_fin <- Sys.time()

# Calcula la diferencia de tiempo
tiempo_transcurrido <- tiempo_fin - tiempo_inicio

# Muestra el resultado y el tiempo transcurrido
# print(resultado)
print(paste("Tiempo transcurrido: ", tiempo_transcurrido))
