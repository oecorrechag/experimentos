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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main(int argc, char *argv[]){
    size_t **matrix; 
    size_t **resultado; 
    size_t N = 500;
    clock_t inicio, fin;
    double tiempo_transcurrido;
    srand(time(NULL));

    // Memoria dinamica
    matrix = (size_t **)calloc(N, sizeof(size_t *)); 
    for(size_t i = 0; i < N; ++i) 
        matrix[i] = (size_t *)malloc(N * sizeof(size_t)); 


    // Inicializa una matriz y la llena
    for(size_t i = 0; i < N; ++i){ 
        for(size_t j = 0; j < N; ++j){
            matrix[i][j] = (size_t) rand()%100 + 1;
        }   
    }
    

    // // imprime la matriz generada
    // for(size_t i = 0; i < N; ++i){ 
    //     for(size_t j = 0; j < N; ++j) { 
    //         printf("%zu", matrix[i][j]); 
    //     }
    //     printf("\n");
    // }


    // Memoria dinamica -> salida resultado
    resultado = (size_t **)calloc(N, sizeof(size_t *)); 
    for(size_t i = 0; i < N; ++i) 
        resultado[i] = (size_t *)malloc(N * sizeof(size_t)); 


    // Registra el tiempo de inicio
    inicio = clock();


    // Multiplicación de la matriz por sí misma
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                resultado[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }


    // #pragma omp parallel
    // {
    //     // Multiplicación de la matriz por sí misma
    //     for (size_t i = 0; i < N; i++) {
    //         for (size_t j = 0; j < N; j++) {
    //             for (size_t k = 0; k < N; k++) {
    //                 resultado[i][j] += matrix[i][k] * matrix[k][j];
    //             }
    //         }
    //     }
    // }
    // return 0;

    // Registra el tiempo de finalización
    fin = clock();

    // Calcula el tiempo transcurrido en segundos
    tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo_transcurrido);
    // printf("%f\n", tiempo_transcurrido);

    // // imprime la matriz generada
    // for(size_t i = 0; i < N; ++i){ 
    //     for(size_t j = 0; j < N; ++j) { 
    //         printf("%zu", resultado[i][j]);
    //     }
    //     printf("\n");
    // }


    // evitar fuga de memoria
    for(size_t i = 0; i < N; ++i) {
        free(matrix[i]); 
        free(resultado[i]);
    }
    free(matrix);
    free(resultado);


}