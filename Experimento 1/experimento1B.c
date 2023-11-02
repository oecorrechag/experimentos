#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 500 // Tamaño de las matrices cuadradas

void multiply_matrices(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Inicializar matrices A y B con valores aleatorios
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    double start_time = omp_get_wtime(); // Registro del tiempo de inicio

    multiply_matrices(A, B, C);

    double end_time = omp_get_wtime(); // Registro del tiempo de finalización

    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
